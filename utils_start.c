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

void	ft_mut_fork(long status, t_philo	*actual)
{
	if (status)
	{
		pthread_mutex_lock(actual->fork_r);
		pthread_mutex_lock(actual->fork_l);
	}
	else if (status == 0)
	{
		pthread_mutex_unlock(actual->fork_l);
		pthread_mutex_unlock(actual->fork_r);
	}
}

long	ft_timestamp(long flag, t_data *data, t_philo *actual, char *str)
{
	long			x;
	struct timeval	ms;

	pthread_mutex_lock(&data->mut_print);
	gettimeofday(&ms, NULL);
	if (actual && actual->data->die_all == 666)
	{
		pthread_mutex_unlock(&data->mut_print);
		return (666);
	}
	x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
	// ft_write_num((x - data->start));
	// ft_write(1, " ");

	if (!actual)
	{
		printf("%ld %ld %s", x - data->start, flag - 1, str);
		// ft_write_num(flag - 1);
		return (0);
	}
	// else
		// ft_write_num(actual->name);
	if (actual && x - actual->last_eat > data->die_t / 1000)
	{
		printf("%ld %ld died  + while %s", x - data->start, actual->name, str + 3);
		// ft_write(1, " \t\t\tdied +\n");
		actual->data->die_all = 666;
		pthread_mutex_unlock(&data->mut_print);
		return (666);
	}
	else
		// ft_write(1, str);
		printf("%ld %ld %s", x - data->start, actual->name, str);
	if (flag == -1)
		actual->last_eat = x;
	else if (flag == -2)
		actual->last_sleep = x;
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

long	ft_usleep(int flag, t_philo *actual, t_data *data)
{
	struct timeval	ms;
	long			x;
	long			y;
	long			z;

	y = 0;
	gettimeofday(&ms, NULL);
	x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
	if (flag == -1)
	{
		x -= actual->last_eat;
		y = data->eat_t / 1000;
		z = x;
	}
	else if (flag == -2)
	{
		z = x - actual->last_eat;
		x -= actual->last_sleep;
		y = data->sleep_t / 1000;
	}
	while (x < y)
	{
		// printf("\t%ld\n", y - x);
		if (flag != -1 && (x > data->die_t / 1000 || z > data->die_t / 1000))
		{
			// pthread_mutex_lock(&data->mut_die);
			actual->data->die_all = 666;
			printf("%ld %ld died  +++\n", z, actual->name);
			return (666);
		}
		usleep(y - x);
		gettimeofday(&ms, NULL);
		x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;// - actual->last_eat;
		if (flag == -1)
		{
			x -= actual->last_eat;
			y = data->eat_t / 1000;
			z = x;
		}
		else if (flag == -2)
		{
			z = x - actual->last_eat;
			x -= actual->last_sleep;
			y = data->sleep_t / 1000;
		}
	}
	return (0);
}
