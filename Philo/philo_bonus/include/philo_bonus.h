/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:15:56 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/22 15:13:31 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <errno.h>
# include <signal.h>

typedef struct s_data
{
	int					number;
	sem_t				*semaphore;
	sem_t				*display;
	long				time_eat;
	long				time_sleep;
	long				time_die;
	long				current_time;
	int					notepme;
}	t_data;

typedef struct s_philo
{
	int				id;
	long			last_time_eating;
	int				counter;
	pid_t			pid;
	int				start;
	t_data			*data;
}	t_philo;

int		check_arg(int ac, char **argv);
void	init(t_data *data, int ac, char **argv);
long	ft_time(long start);
void	ft_usleep(long time);
int		ft_atoi(const char *ptr);
void	init_philo(t_data *data, t_philo *philo);
void	process(t_philo *philo);
void	dining_room(t_philo *philo);
void	*routine(void *arg);
void	affichage(t_philo *philo, char *str, long time);
#endif
