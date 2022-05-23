/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:16:36 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/22 18:03:15 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

long	ft_time(long start)
{
	struct timeval	current_time;
	long			time;

	gettimeofday(&current_time, NULL);
	time = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	return (time - start);
}

void	ft_usleep(long time)
{
	long	current_time;

	current_time = ft_time(0);
	usleep(time / 1000);
	while (ft_time(current_time) * 1000 < time)
		usleep(100);
}

void	init(t_data *data, int ac, char **argv)
{
	data->number = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (ac == 6)
		data->notepme = ft_atoi(argv[5]);
	else
		data->notepme = -1;
	sem_unlink("mutex");
	sem_unlink("display");
	data->semaphore = sem_open("mutex", O_CREAT, 0664, data->number);
	data->display = sem_open("display", O_CREAT, 0664, 1);
	if (data->semaphore == SEM_FAILED || data->display == SEM_FAILED)
		perror("[sem_open] Failed\n");
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].last_time_eating = 0;
		philo[i].counter = 0;
		philo[i].start = 0;
		i++;
	}
}

void	process(t_philo *philo)
{
	int	i;
	int	id;

	i = 0;
	philo[0].data->current_time = ft_time(0);
	while (i < (philo[0].data->number))
	{
		id = fork();
		if (id != 0)
			philo[i].pid = id;
		if (id == 0)
			dining_room(&philo[i]);
		i++;
		usleep(100);
	}
}
