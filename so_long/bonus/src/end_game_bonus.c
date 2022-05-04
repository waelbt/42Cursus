/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:41 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/03 18:44:22 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	end_game(t_vars *v, char *str)
{
	static int	i[2];
	int			p[4];
	char		*ptr;

	v->matrix[i[1]][i[0]] = '0';
	ptr = "press any key to quit";
	ft_render(v, v->wall.frame1, v->count.frame1);
	if (i[0] >= v->width)
	{
		i[0] = -1;
		i[1]++;
	}
	if (i[1] >= v->height)
	{
		v->exit_counter = -1;
		v->enemy_counter = -1;
		p[0] = IMG_SIZE * (v->width - 1) / 2;
		p[1] = IMG_SIZE * v->height / 2;
		p[2] = IMG_SIZE * (v->width - 3) / 2;
		p[3] = IMG_SIZE * (v->height + 1) / 2;
		mlx_string_put(v->mlx, v->win, p[0], p[1], 0xCE00FF, str);
		mlx_string_put(v->mlx, v->win, p[2], p[3], 0xCE00FF, ptr);
	}
	i[0]++;
}

int	animation(t_vars *v)
{
	static int	i;

	if (v->exit_counter == count_char(v, 'E'))
	{
		ft_render(v, v->wall.frame1, v->count.frame1);
		ft_render(v, v->wall.frame2, v->count.frame2);
		ft_render(v, v->wall.frame3, v->count.frame3);
		mlx_string_put(v->mlx, v->win, 42, 30, 0xCE00FF, ft_itoa(v->moves));
	}
	if (v->exit_counter != count_char(v, 'E')
		&& v->exit_counter != -1 && i != 3)
	{
		i = 1;
		end_game(v, "you win !!");
	}
	if (v->enemy_counter != count_char(v, 'H')
		&& v->enemy_counter != -1 && i != 1)
	{
		i = 3;
		end_game(v, "game over ^)");
	}
	return (0);
}

void	norm54(t_vars *v, int i, int j)
{
	if (v->matrix[j][i] == 'C')
		mlx_put_image_to_window(v->mlx, v->win,
			v->assests.frame1, IMG_SIZE * i, IMG_SIZE * j);
	else if (v->matrix[j][i] == 'P')
		mlx_put_image_to_window(v->mlx, v->win,
			v->assests.frame2, IMG_SIZE * i, IMG_SIZE * j);
	else if (v->matrix[j][i] == 'E')
		mlx_put_image_to_window(v->mlx, v->win,
			v->assests.frame3, IMG_SIZE * i, IMG_SIZE * j);
	else if (v->matrix[j][i] == 'H')
	{
		mlx_put_image_to_window(v->mlx, v->win, v->bg,
			IMG_SIZE * i, IMG_SIZE * j);
		if (target_near(v, i, j))
			angry_enmey(v, v->angry, i, j);
		else
			angry_enmey(v, v->enemy, i, j);
	}
}

int	one_field(t_vars *v, int x, int y)
{
	if (x < v->height && y < v->width
		&& x > 0 && y > 0)
		return (1);
	return (0);
}

int	target_near(t_vars *v, int x, int y)
{
	int	i;
	int	j;

	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			if (one_field(v, y + i, x + j))
			{
				if (v->matrix[y + i][x + j] == 'P')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
