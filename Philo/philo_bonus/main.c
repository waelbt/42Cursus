/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:16:34 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/22 14:12:14 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philo_bonus.h"

void	kill_all(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].data->number)
	{
		kill(philo[i].pid, SIGINT);
		i++;
	}
}

void	affichage(t_philo *philo, char *str, long time)
{
	sem_wait(philo->data->display);
	printf("%ld | philo %d %s\n", time, philo->id, str);
	sem_post(philo->data->display);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;
	int		res_wait;
	int		status;

	res_wait = 0;
	status = 0;
	data = (t_data *) malloc(sizeof(t_data));
	if (argc < 5 || argc > 6
		|| !check_arg(argc, argv))
	{
		printf("Invalid arguments\n");
		return (0);
	}
	init(data, argc, argv);
	philo = (t_philo *) malloc(sizeof(t_philo) * data->number);
	init_philo(data, philo);
	process(philo);
	while (res_wait != -1 && status == 0)
		res_wait = waitpid(-1, &status, 0);
	kill_all(philo);
	sem_close(data->semaphore);
	sem_close(data->display);
	return (0);
}
