/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:22:56 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/23 11:47:41 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int					number;
	pthread_mutex_t		*forks;
	pthread_mutex_t		display;
	pthread_mutex_t		*data_race;
	long				time_eat;
	long				time_sleep;
	long				time_die;
	long				current_time;
	int					notepme;
	int					is_dead;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	long			last_time_eating;
	int				counter;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

void	threads(t_philo *philo);
void	init_philo(t_data *data, t_philo *philo);
void	affichage(t_philo *philo, char *str, long time);
int		init(t_data *data, int ac, char **argv);
void	*dining_room(void *arg);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
int		dead(t_philo *philo);
void	destory(t_data *data);
int		ft_norm(t_philo *philo, int i);
int		check_arg(int ac, char **argv);
long	ft_time(long start);
void	ft_usleep(long time);
int		ft_atoi(const char *ptr);
#endif
