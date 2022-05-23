/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:16:40 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/22 18:02:39 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->data->semaphore);
	affichage(philo, "take fork", ft_time(philo->data->current_time));
	philo->start = 1;
	sem_wait(philo->data->semaphore);
	affichage(philo, "take fork", ft_time(philo->data->current_time));
	affichage(philo, "start eating", ft_time(philo->data->current_time));
	philo->last_time_eating = ft_time(philo->data->current_time);
	ft_usleep(philo->data->time_eat * 1000);
	philo->counter++;
}

void	sleeping(t_philo *philo)
{
	sem_post(philo->data->semaphore);
	sem_post(philo->data->semaphore);
	if (philo->counter >= philo->data->notepme && philo->data->notepme != -1)
		exit(0);
	affichage(philo, "sleeping", ft_time(philo->data->current_time));
	ft_usleep(philo->data->time_sleep * 1000);
}

void	dead(t_philo *philo, long time)
{
	sem_wait(philo->data->display);
	printf("%ld | philo %d dead \n", time, philo->id);
	exit(1);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	long	time;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->start == 1)
		{
			time = ft_time(philo->data->current_time + philo->last_time_eating);
			if (philo->data->time_die <= time)
				dead(philo, ft_time(philo->data->current_time));
		}
	}
	return (NULL);
}

void	dining_room(t_philo *philo)
{
	pthread_t	th;

	if (pthread_create(&th, NULL, &routine, philo) != 0)
		perror("failed to create thread");
	while (1)
	{
		eating(philo);
		sleeping(philo);
		affichage(philo, "thinking", ft_time(philo->data->current_time));
	}
}
