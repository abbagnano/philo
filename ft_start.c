/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <fgradia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:14:23 by fgradia           #+#    #+#             */
/*   Updated: 2021/07/21 18:35:59 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philolib.h"

void	ft_eat_sleep_think_old(t_philo	*actual)
{
	
	// ft_mut_fork(1, actual);
	// if (ft_thinking(actual) == 666)
	// 	return (ft_mut_fork(0, actual));
	// ft_mut_fork(0, actual);
	// ft_mut_fork(1, actual);
	// if (ft_timestamp(0, actual->data, actual, " is thinking\n") == 666)
	// while (*actual->f_l_stat == 1 || *actual->f_r_stat == 1)
	// {
	// 	// ft_mut_fork(0, actual);
	// 	// ft_mut_fork(1, actual);
	// 	continue ;
	// }
	// ft_mut_fork(0, actual);
	// ft_mut_fork(1, actual);
	// if (*actual->f_l_stat == 1 || *actual->f_r_stat == 1)
	// {
		
	// 	return ;//(ft_mut_fork(0, actual));
	// }
				// if (ft_thinking(actual) == 666)
				// {
				// 	// pthread_mutex_unlock(&actual->data->mut_die);
				// 	return ;//(ft_mut_fork(0, actual));
				// }
	// long x;

	// struct timeval	ms;
	// while (*actual->f_l_stat == 1 || *actual->f_r_stat == 1)
	// {
	// 	if (actual->data->die_all == 666)
	// 		return ;//(666);
	// 	gettimeofday(&ms, NULL);
	// 	x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
	// 	x -= actual->last_eat;
	// 	if (x > actual->data->die_t / 1000)
	// 	{
	// 		// pthread_mutex_lock(&actual->data->mut_die);
	// 		actual->data->die_all = 666;
	// 		printf("%ld %ld died  ++\n", x /*- actual->data->start*/, actual->name);
	// 		return ;//(666);
	// 	}
	// }


	// ft_mut_fork(0, actual);
	ft_mut_fork(1, actual);
	if (*actual->f_l_stat == 1 || *actual->f_r_stat == 1)
		return (ft_mut_fork(0, actual));
	// int r;
	// r = ft_forking_eating(actual);
	// printf("\t\t%d\n", r);
	// if (r /*= ft_forking_eating(actual))*/ == 666)
	if (ft_forking_eating(actual) == 666)
		return (ft_mut_fork(0, actual));
	// ft_mut_fork(0, actual);
	// ft_mut_fork(1, actual);
	if (ft_usleep(-1, actual, actual->data) == 666)
		return ;//(ft_mut_fork(0, actual));
	// usleep(actual->data->eat_t);
	actual->eat_n--;
	// ft_mut_fork(0, actual);
	// ft_mut_fork(1, actual);
	if (ft_sleeping(actual) == 666)
		return (ft_mut_fork(0, actual));
	ft_mut_fork(0, actual);
	// pthread_mutex_lock(&actual->data->mut_die);
	// usleep(actual->data->sleep_t);
	if (ft_usleep(-2, actual, actual->data) == 666) 
	{
		// pthread_mutex_unlock(&actual->data->mut_die);
		return ;//(ft_mut_fork(0, actual));
	}
		if (ft_thinking(actual) == 666)
	{
		// pthread_mutex_unlock(&actual->data->mut_die);
		return ;//(ft_mut_fork(0, actual));
	}
	// pthread_mutex_unlock(&actual->data->mut_die);
	// ft_mut_fork(1, actual);
	// pthread_mutex_lock(&actual->data->mut_die);
				// if (ft_thinking(actual) == 666)
				// {
				// 	// pthread_mutex_unlock(&actual->data->mut_die);
				// 	return ;//(ft_mut_fork(0, actual));
				// }
	// pthread_mutex_unlock(&actual->data->mut_die);// ft_mut_fork(0, actual);
}

void	ft_eat_sleep_think(t_philo	*actual)
{
	// struct timeval	ms;
	// long			x;
	//
	// while (*actual->f_l_stat == 1 || *actual->f_r_stat == 1)
	// {
	// 	// if (actual->data->die_all == 666)
	// 	// 	return (666);
	// 	pthread_mutex_lock(&actual->data->mut_print);
	// 	gettimeofday(&ms, NULL);
	// 	x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
	// 	x -= actual->last_eat;
	// 	if (x > actual->data->die_t / 1000)
	// 	{
	// 		// pthread_mutex_lock(&actual->data->mut_print);
	// 		actual->data->die_all = 666;
	// 		printf("%ld %ld died ++-++\n", x /*- actual->data->start*/, actual->name);
	// 		pthread_mutex_unlock(&actual->data->mut_print);
	// 		return ;//(666);
	// 	}
	// 	pthread_mutex_unlock(&actual->data->mut_print);
	// 	// printf(" asdasda\n");
	// }
	// ft_mut_fork(1, actual);
		if (ft_thinking(actual))
		return ;
	pthread_mutex_lock(actual->fork_r);
	pthread_mutex_lock(actual->fork_l);
	*actual->f_r_stat = 1;
	if (ft_timestamp(0, actual->data, actual, " has taken a fork\n"))
	{
		pthread_mutex_unlock(actual->fork_r);
		return ;//(ft_mut_fork(0, actual));//(666);
	}
	*actual->f_l_stat = 1;
	if (ft_timestamp(0, actual->data, actual, " has taken a fork\n"))
		return (ft_mut_fork(0, actual));//(666);
	if (ft_timestamp(-1, actual->data, actual, "\033[0;32m is eating\033[0m\n"))
		return (ft_mut_fork(0, actual));
	if (ft_usleep(-1, actual, actual->data))
		return (ft_mut_fork(0, actual));//(ft_mut_fork(0, actual));
	actual->eat_n--;
	if (ft_timestamp(-2, actual->data, actual, " is sleeping\n"))
		return (ft_mut_fork(0, actual));//(666);
	*actual->f_r_stat = 0;
	pthread_mutex_unlock(actual->fork_r);
	*actual->f_l_stat = 0;
	pthread_mutex_unlock(actual->fork_l);
	// ft_mut_fork(0, actual);
	if (ft_usleep(-2, actual, actual->data))
		return ;//(ft_mut_fork(0, actual));
	// if (ft_timestamp(0, actual->data, actual, " is thinking\n"))
	// 	return ;
	// if (ft_thinking(actual))
	// 	return ;

}

void	*ft_alone(t_philo *actual)
{
	struct timeval	ms;
	long			x;

	*actual->f_r_stat = 1;
	if (ft_timestamp(0, actual->data, actual, " has taken a fork\n"))
		return NULL;//(ft_mut_fork(0, actual));//(666);

	while (*actual->f_r_stat == 1)// || *actual->f_r_stat == 1)
	{
		// if (actual->data->die_all == 666)
		// 	return (666);
		gettimeofday(&ms, NULL);
		x = ms.tv_sec % 1000 * 1000 + ms.tv_usec / 1000;
		x -= actual->last_eat;
		// pthread_mutex_lock(&actual->data->mut_print);
		if (x > actual->data->die_t / 1000)
		{
			// pthread_mutex_lock(&actual->data->mut_print);
			actual->data->die_all = 666;
			printf("%ld %ld died ++ ++\n", x /*- actual->data->start*/, actual->name);
			// pthread_mutex_unlock(&actual->data->mut_print);
			return (NULL);//(666);
		}
		// pthread_mutex_unlock(&actual->data->mut_print);
		// printf(" asdasda\n");
	}
	return NULL;
}	

void	*ft_routine(void *arg)
{
	t_philo			*actual;

	actual = (t_philo *)arg;
	// ft_mut_fork(1, actual);
	// ft_thinking(actual);
	// ft_mut_fork(0, actual);
	if (actual->name % 2 == 0)
		usleep(23);//(actual->data->eat_t - 10);
	// {
	// 	int x = 0;
	// 	while (x < 42)
	// 		x++;
	// }
	if (actual->data->phils_n == 1)
		return (ft_alone(actual));

	while (actual->eat_n != 0 && actual->data->die_all != 666)
		ft_eat_sleep_think(actual);
//	printf("qweqweqweqw %d\n", actual->name);
	// if (actual->data->die_all == 666)
		// pthread_mutex_lock(&actual->data->mut_die);
	return (NULL);
}

void	ft_create_philo(t_philo **philos, long *fork,
		pthread_mutex_t *mut_fork, t_data *data)
{
	long	x;

	x = 0;
	while (x < data->phils_n)
	{
		philos[x] = (t_philo *)malloc(sizeof(t_philo) * 1);
		philos[x]->phil = (pthread_t *)malloc(sizeof(pthread_t) * 1);
		philos[x]->name = x + 1;
		philos[x]->eat_n = data->eat_n;
		philos[x]->last_eat = data->start;
		philos[x]->last_sleep = data->start;
		philos[x]->f_l_stat = &fork[x];
		philos[x]->fork_l = &mut_fork[x];
		philos[x]->f_r_stat = &fork[ft_next_phil(x, data->phils_n)];
		philos[x]->fork_r = &mut_fork[ft_next_phil(x, data->phils_n)];
		philos[x]->data = data;
		if (pthread_create(philos[x]->phil, NULL,
				ft_routine, (void *)philos[x]) != 0)
			ft_exit("Error: a philo didn't seat\n", data);
		x++;
	}
	// ft_lets_die(1, philos, data);
}

void	ft_start(t_data *data)
{
	long			x;
	long			*fork;
	t_philo			**philos;
	pthread_mutex_t	*mut_fork;

	fork = (long *)malloc(sizeof(long) * data->phils_n);
	ft_init_array(fork, 0, data->phils_n);
	philos = (t_philo **)malloc(sizeof(t_philo *) * data->phils_n);
	mut_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (data->phils_n));
	x = 0;
	while (x < data->phils_n)
		pthread_mutex_init(&mut_fork[x++], NULL);
	pthread_mutex_init(&data->mut_die, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	ft_create_philo(philos, fork, mut_fork, data);
	ft_join_philo(philos, data);
	// pthread_mutex_lock(&data->mut_die);
		long	xx;

	xx = 0;
	while (xx < data->phils_n)
	{
		if (philos[xx]->eat_n != 0)// || philos[x]->die == 666)
			break ;
		xx++;
	}
	if (xx == data->phils_n)
	{
		ft_write(1, "hanno mangiato tutti\n");
		// return ;
		// pthread_mutex_unlock(&data->mut_die);
	}
	// else
	// {
	// 	ft_lets_die(0, philos, data);
	// 	pthread_mutex_unlock(&data->mut_die);
	// }

	// ft_lets_die(1, philos, data);
	x = 0;
	while (x < data->phils_n)
		pthread_mutex_destroy(&mut_fork[x++]);
	pthread_mutex_destroy(&data->mut_die);
	pthread_mutex_destroy(&data->mut_print);
	ft_free(fork, philos, mut_fork, data);
}
