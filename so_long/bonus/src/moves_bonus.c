/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bouns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:16 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/21 05:16:21 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
				data->x = i;
				data->y = j;
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
	if (d->e != find_exit(d))
		return ;
	d->matrix[d->x + i][d->y + j] = 'P';
	d->matrix[d->x][d->y] = '0';
	d->moves++;
}

void	moves(t_vars *d, int keycode)
{
	static char	c = 'E';

	find_player(d);
	if (d->e == -1)
		exit(0);
	if (keycode == 97 && charcmp(d->matrix[d->x][d->y - 1], '1', c))
		ft_norm(d, 0, -1);
	if (keycode == 115 && charcmp(d->matrix[d->x + 1][d->y], '1', c))
		ft_norm(d, 1, 0);
	if (keycode == 100 && charcmp(d->matrix[d->x][d->y + 1], '1', c))
		ft_norm(d, 0, 1);
	if (keycode == 119 && charcmp(d->matrix[d->x - 1][d->y], '1', c))
		ft_norm(d, -1, 0);
	if (!count_c(d))
	{
		initialise_images(d, "2.xpm");
		c = '1';
	}
}
