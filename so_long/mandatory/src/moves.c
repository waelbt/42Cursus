/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:16 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/05 15:44:28 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_player(t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->matrix[i][j] == 'P')
			{
				data->posx = i;
				data->posy = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	find_exit(t_vars *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->matrix[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_c(t_vars *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->matrix[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_norm(t_vars *d, int i, int j)
{
	d->matrix[d->posx + i][d->posy + j] = 'P';
	d->matrix[d->posx][d->posy] = '0';
	d->moves++;
	ft_putstr("moves number: ");
	ft_putnbr(d->moves);
	ft_putstr("\n");
}

void	moves(t_vars *d, int keycode)
{
	static char	c = 'E';

	find_player(d);
	if (keycode == 97 && charcmp(d->matrix[d->posx][d->posy - 1], '1', c))
		ft_norm(d, 0, -1);
	if (keycode == 115 && charcmp(d->matrix[d->posx + 1][d->posy], '1', c))
		ft_norm(d, 1, 0);
	if (keycode == 100 && charcmp(d->matrix[d->posx][d->posy + 1], '1', c))
		ft_norm(d, 0, 1);
	if (keycode == 119 && charcmp(d->matrix[d->posx - 1][d->posy], '1', c))
		ft_norm(d, -1, 0);
	if (!count_c(d))
	{
		initialise_images(d, "2.xpm");
		c = '1';
	}
	if (d->e != find_exit(d))
	{
		ft_putstr("you win\n");
		exit(0);
	}
}
