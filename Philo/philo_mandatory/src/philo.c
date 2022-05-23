/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:45:26 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/23 12:05:11 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*dining_room(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		pthread_mutex_lock(&philo->data->data_race[1]);
		if (philo->data->is_dead == 0)
			affichage(philo, "thinking", ft_time(philo->data->current_time));
		pthread_mutex_unlock(&philo->data->data_race[1]);
	}
	return (NULL);
}

pthread_mutex_t	*init_mutex(pthread_mutex_t *mutex, int size)
{
	int	i;

	i = 0;
	mutex = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * size);
	if (!mutex)
		return (NULL);
	while (i < size)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

int	init(t_data *data, int ac, char **argv)
{
	data->number = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->is_dead = 0;
	data->data_race = init_mutex(data->data_race, 3);
	data->forks = init_mutex(data->forks, data->number);
	if (!data->data_race || !data->forks)
		return (0);
	pthread_mutex_init(&data->display, NULL);
	if (ac == 6)
		data->notepme = ft_atoi(argv[5]);
	else
		data->notepme = -1;
	return (1);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->number)
	{
		philo[i].id = i + 1;
		philo[i].left = i;
		philo[i].right = i + 1;
		philo[i].data = data;
		philo[i].last_time_eating = 0;
		philo[i].counter = 0;
		if (i == data->number - 1)
			philo[i].right = 0;
		i++;
	}
}

void	threads(t_philo *philo)
{
	int	i;

	i = 0;
	philo->data->current_time = ft_time(0);
	while (i < philo[0].data->number)
	{
		if (pthread_create(&philo[i].thread, NULL,
				&dining_room, &philo[i]) != 0)
			perror("failed to create thread");
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < philo[0].data->number)
	{
		if (pthread_create(&philo[i].thread, NULL,
				&dining_room, &philo[i]) != 0)
			perror("failed to create thread");
		i += 2;
	}
}
