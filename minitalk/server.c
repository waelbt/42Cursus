/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:45:54 by waboutzo          #+#    #+#             */
/*   Updated: 2022/02/28 18:50:55 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int number,	int force)
{
	int	save;
	int	i;

	i = 0;
	save = 1;
	while (i < force)
	{
		save *= number;
		i++;
	}
	return (save);
}

void	handler(int signum)
{
	static int	i = 7;
	static char	decimal;

	if (SIGUSR1 == signum)
		decimal += ft_pow(2, i);
	i--;
	if (i == -1)
	{
		write(1, &decimal, 1);
		decimal = 0;
		i = 7;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
