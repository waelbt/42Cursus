/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:16 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/03 18:45:15 by waboutzo         ###   ########.fr       */
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
				data->posx = i;
				data->posy = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	count_char(t_vars *data, char c)
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
			if (data->matrix[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_norm(t_vars *d, int i, int j)
{
	if (d->exit_counter != count_char(d, 'E')
		|| d->enemy_counter != count_char(d, 'H'))
		return ;
	d->matrix[d->posx + i][d->posy + j] = 'P';
	d->matrix[d->posx][d->posy] = '0';
	d->moves++;
}

void	moves(t_vars *d, int keycode)
{
	static char	c = 'E';

	find_player(d);
	if (d->exit_counter == -1)
		exit(0);
	if (keycode == 97 && charcmp(d->matrix[d->posx][d->posy - 1], '1', c))
		ft_norm(d, 0, -1);
	if (keycode == 115 && charcmp(d->matrix[d->posx + 1][d->posy], '1', c))
		ft_norm(d, 1, 0);
	if (keycode == 100 && charcmp(d->matrix[d->posx][d->posy + 1], '1', c))
		ft_norm(d, 0, 1);
	if (keycode == 119 && charcmp(d->matrix[d->posx - 1][d->posy], '1', c))
		ft_norm(d, -1, 0);
	if (!count_char(d, 'C'))
	{
		initialise_images(d, "2.xpm");
		c = '1';
	}
}

void	angry_enmey(t_vars *v, t_frames f, int i, int j)
{
	if (v->counter >= 0 && v->counter < 100)
		mlx_put_image_to_window(v->mlx, v->win,
			f.frame1, IMG_SIZE * i, IMG_SIZE * j);
	if (v->counter >= 100 && v->counter < 200)
		mlx_put_image_to_window(v->mlx, v->win,
			f.frame2, IMG_SIZE * i, IMG_SIZE * j);
	if (v->counter >= 200 && v->counter < 300)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			f.frame3, IMG_SIZE * i, IMG_SIZE * j);
		if (v->counter == 299)
			v->counter = 0;
	}
	v->counter++;
}
