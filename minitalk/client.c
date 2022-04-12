/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:08:56 by waboutzo          #+#    #+#             */
/*   Updated: 2022/02/26 17:09:32 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc,	char **argv)
{
	int		i;
	int		j;
	pid_t	pid;

	j = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][j])
		{
			i = 7;
			while (0 <= i)
			{
				if (argv[2][j] & (1 << i))
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				usleep(200);
				i--;
			}
			j++;
		}
	}
}
