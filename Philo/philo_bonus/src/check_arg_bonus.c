/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:16:38 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/22 18:02:58 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo_bonus.h"

int	max_min_value(int stock, int signe, int i)
{
	if (i >= 19 && signe < 0)
		return (stock = 0);
	if (i >= 19 && signe > 0)
		return (stock = -1);
	else
		return (stock);
}

int	ft_atoi(const char *ptr)
{
	int	signe;
	int	i;
	int	stock;

	i = 0;
	signe = 1;
	stock = 0;
	while (ptr[i] == ' ' || ptr[i] == '\n' || ptr[i] == '\t'
		|| ptr[i] == '\v' || ptr[i] == '\r' || ptr[i] == '\f')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			signe *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		stock = (stock * 10) + (ptr[i] - '0');
		i++;
	}
	stock = max_min_value(stock, signe, i);
	return (stock * signe);
}

int	ft_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int ac, char **argv)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(argv[i]) == 0)
			return (0);
		if (!ft_numeric(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
