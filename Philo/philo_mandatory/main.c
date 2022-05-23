/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 10:52:38 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/23 12:04:15 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo.h"

long	ft_time(long start)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000
		+ current_time.tv_usec / 1000 - start);
}

void	ft_usleep(long time)
{
	long	current_time;

	current_time = ft_time(0);
	usleep(time / 1000);
	while (ft_time(current_time) * 1000 < time)
		usleep(100);
}

int	full_philo(t_philo *philo, int i, int *j)
{
	pthread_mutex_lock(&philo->data->data_race[2]);
	if (philo[i].counter >= philo[0].data->notepme
		&& philo->data->notepme != -1)
			(*j)++;
	pthread_mutex_unlock(&philo->data->data_race[2]);
	if (!ft_norm(philo, *j))
		return (0);
	return (1);
}

void	supervisor(t_philo *philo)
{
	int	i[2];
	int	time;

	while (1)
	{
		i[0] = 0;
		i[1] = 0;
		while (i[0] < philo[0].data->number)
		{
			if (!full_philo(philo, i[0], &i[1]))
				return ;
			pthread_mutex_lock(&philo->data->data_race[0]);
			time = ft_time(philo[i[0]].data->current_time
					+ philo[i[0]].last_time_eating);
			pthread_mutex_unlock(&philo->data->data_race[0]);
			if (philo[i[0]].data->time_die <= time)
			{
				if (!dead(&philo[i[0]]))
					return ;
			}
			i[0]++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data || argc < 5 || argc > 6 || !check_arg(argc, argv))
	{
		printf("invalid arguments\n");
		return (0);
	}
	if (!init(data, argc, argv))
		return (0);
	philo = (t_philo *) malloc(sizeof(t_philo) * data->number);
	if (!philo)
		return (0);
	init_philo(data, philo);
	threads(philo);
	supervisor(philo);
	destory(data);
}
