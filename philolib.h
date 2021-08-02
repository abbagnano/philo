/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philolib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgradia <fgradia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:14:11 by fgradia           #+#    #+#             */
/*   Updated: 2021/07/21 18:35:17 by fgradia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOLIB_H
# define PHILOLIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	long			phils_n;
	long			die_t;
	long			eat_t;
	long			sleep_t;
	long			eat_n;
	long			start;
	long			die_all;
	pthread_mutex_t	mut_die;
	pthread_mutex_t	mut_print;
}	t_data;

typedef struct s_philo
{
	pthread_t		*phil;
	long			name;
	long			eat_n;
	long			last_eat;
	long			last_sleep;
	long			*f_l_stat;
	pthread_mutex_t	*fork_l;
	long			*f_r_stat;
	pthread_mutex_t	*fork_r;
	t_data			*data;
}	t_philo;

/*		philo.c		****	MAIN	****	*/
long	ft_prec_phil(long actual, long phils_n);
long	ft_next_phil(long actual, long phils_n);
void	ft_init_array(long *array, long val, long phils_n);
void	ft_init_data(char **av, t_data *data);

/*		ft_exit.c	*/
void	ft_mut_fork(long status, t_philo	*actual);
long	ft_thinking(t_philo *actual);
void	ft_check_eat(t_data *data, t_philo **philos);
void	ft_free(long *fork, t_philo **philos,
			pthread_mutex_t *mut_fork, t_data *data);
void	ft_exit(char *str, t_data *data);

/*		ft_start.c	*/
void	ft_eat_sleep_think(t_philo	*actual);
void	*ft_alone(t_philo *actual);
void	*ft_routine(void *arg);
void	ft_create_philo(t_philo **philos, long *fork,
			pthread_mutex_t *mut_fork, t_data *data);
void	ft_start(t_data *data);

/*	utils_basic.c	*/
long	ft_strncmp(char *s1, char *s2, long len);
long	ft_strlen(char *str);
void	ft_write(long fd, char *str);
long	ft_atoi(char *str);
void	ft_write_num(long num);

/*	utils_start.c	*/
int		ft_dead(long x, t_philo *actual, t_data *data);
long	ft_timestamp(long flag, t_data *data, t_philo *actual, char *str);
void	ft_join_philo(t_philo **philos, t_data *data);
long	ft_usleep(int flag, t_philo *actual, t_data *data);

#endif