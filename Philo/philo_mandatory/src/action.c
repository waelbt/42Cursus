/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 15:28:00 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/23 11:51:00 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_race[1]);
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_unlock(&philo->data->data_race[1]);
		pthread_mutex_lock(&philo->data->forks[philo->left]);
		affichage(philo, "take fork",
			ft_time(philo->data->current_time));
		pthread_mutex_lock(&philo->data->forks[philo->right]);
		affichage(philo, "take fork",
			ft_time(philo->data->current_time));
		affichage(philo, "start eating",
			ft_time(philo->data->current_time));
		pthread_mutex_lock(&philo->data->data_race[0]);
		philo->last_time_eating = ft_time(philo->data->current_time);
		pthread_mutex_unlock(&philo->data->data_race[0]);
		ft_usleep(philo->data->time_eat * 1000);
		pthread_mutex_lock(&philo->data->data_race[2]);
		philo->counter++;
		pthread_mutex_unlock(&philo->data->data_race[2]);
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		pthread_mutex_unlock(&philo->data->forks[philo->right]);
	}
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->data_race[1]);
	if (philo->data->is_dead == 0)
	{
		pthread_mutex_unlock(&philo->data->data_race[1]);
		affichage(philo, "sleeping",
			ft_time(philo->data->current_time));
		ft_usleep(philo->data->time_sleep * 1000);
	}
}

int	dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->display);
	pthread_mutex_lock(&philo->data->data_race[1]);
	philo->data->is_dead = 1;
	pthread_mutex_unlock(&philo->data->data_race[1]);
	printf("%ld | philo %d dead \n",
		ft_time(philo->data->current_time), philo->id);
	return (0);
}

void	destory(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number)
		pthread_mutex_destroy(&data->forks[i++]);
	i = 0;
	while (i < 3)
		pthread_mutex_destroy(&data->data_race[i++]);
	pthread_mutex_destroy(&data->display);
}

int	ft_norm(t_philo *philo, int i)
{
	if (i == philo[0].data->number)
	{
		pthread_mutex_lock(&philo->data->display);
		return (0);
	}
	return (1);
}
