/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <fgradia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:14:33 by fgradia           #+#    #+#             */
/*   Updated: 2021/07/21 18:11:52 by fgradia          ###   ########.fr       */
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

long	ft_thinking(t_philo *actual)
{
	struct timeval	ms;
	long			x;

	if (actual->data->die_all == 666
		|| ft_timestamp(0, actual->data, actual, " is thinking\n"))
		return (666);
	while (*actual->f_r_stat == 1)
	{
		gettimeofday(&ms, NULL);
		x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
		if (x - actual->last_eat > actual->data->die_t / 1000)
		{
			pthread_mutex_lock(&actual->data->mut_print);
			return (ft_dead(x - actual->data->start, actual, actual->data));
		}
	}
	return (0);
}

void	ft_check_eat(t_data *data, t_philo **philos)
{
	long	x;

	x = 0;
	while (x < data->phils_n)
	{
		if (philos[x]->eat_n != 0)
			break ;
		x++;
	}
	if (x == data->phils_n)
		ft_write(1, "\033[0;36mhanno mangiato tutti\033[0m\n");
}

void	ft_free(long *fork, t_philo **philos,
		pthread_mutex_t *mut_fork, t_data *data)
{
	int	x;

	x = 0;
	while (x < data->phils_n)
	{
		free(philos[x]->phil);
		free(philos[x++]);
	}
	free(philos);
	free(fork);
	free(mut_fork);
}

void	ft_exit(char *str, t_data *data)
{
	ft_write(2, str);
	ft_write(2, "\n");
	exit(0);
	(void)data;
}
