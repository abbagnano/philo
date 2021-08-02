/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <fgradia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:47:10 by fgradia           #+#    #+#             */
/*   Updated: 2021/07/21 18:36:27 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philolib.h"

int	ft_dead(long x, t_philo *actual, t_data *data)
{
	if (actual && actual->data->die_all == 666)
	{
		pthread_mutex_unlock(&data->mut_print);
		return (666);
	}
	printf("\033[0;31m%ld %ld died  +\033[0m\n", x, actual->name);
	actual->data->die_all = 666;
	pthread_mutex_unlock(&data->mut_print);
	return (666);
}

long	ft_timestamp(long flag, t_data *data, t_philo *act, char *str)
{
	long			x;
	struct timeval	ms;

	pthread_mutex_lock(&data->mut_print);
	gettimeofday(&ms, NULL);
	x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
	if (!act)
	{
		printf("%ld %ld %s", x - data->start, flag - 1, str);
		return (0);
	}
	if (x - act->last_eat > data->die_t / 1000 || act->data->die_all == 666)
		return (ft_dead(x - data->start, act, data));
	else
		printf("%ld %ld %s", x - data->start, act->name, str);
	if (flag == -1)
		act->last_eat = x;
	else if (flag == -2)
		act->last_sleep = x;
	pthread_mutex_unlock(&data->mut_print);
	return (0);
}

void	ft_join_philo(t_philo **philos, t_data *data)
{
	long	x;

	x = 0;
	while (x < data->phils_n)
	{
		if (pthread_join(*philos[x]->phil, NULL) != 0)
			ft_write(1, "\tp_j:error\n");
		x++;
	}
}

void	ft_flag_usleep(int flag, long *x, t_philo *actual)
{
	if (flag == -1)
	{
		x[0] -= actual->last_eat;
		x[1] = actual->data->eat_t / 1000;
		x[2] = x[0];
	}
	else if (flag == -2)
	{
		x[2] = x[0] - actual->last_eat;
		x[0] -= actual->last_sleep;
		x[1] = actual->data->sleep_t / 1000;
	}
}

long	ft_usleep(int flag, t_philo *actual, t_data *data)
{
	struct timeval	ms;
	long			x[3];

	x[1] = 0;
	gettimeofday(&ms, NULL);
	x[0] = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
	ft_flag_usleep(flag, x, actual);
	while (x[0] < x[1])
	{
		if (flag != -1
			&& (x[0] > data->die_t / 1000 || x[2] > data->die_t / 1000))
		{
			pthread_mutex_lock(&actual->data->mut_print);
			return (ft_dead(x[2], actual, data));
		}
		usleep(x[1] - x[0]);
		gettimeofday(&ms, NULL);
		x[0] = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
		ft_flag_usleep(flag, x, actual);
	}
	return (0);
}
