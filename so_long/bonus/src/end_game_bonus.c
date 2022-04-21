/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:41 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/21 17:07:12 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	end_game(t_vars *vars)
{
	static int i;
	static int j;

	if (vars->e != find_exit(vars) && vars->e != -1)
	{
		vars->matrix[j][i] = '0';
		ft_render(vars, vars->wal1, vars->c1);
		if(i >= vars->width)
		{
			i = -1;
			j++;
		}
		if(j >= vars->height)
		{
			vars->e = -1;
			mlx_string_put(vars->mlx, vars->win, (50 * (vars->width - 1) / 2), (50 * vars->height / 2), 0xCE00FF, "you win !!");
			mlx_string_put(vars->mlx, vars->win, (50 * (vars->width - 3) / 2), (50 * (vars->height + 1)/ 2), 0xCE00FF, "press in key to exit");
		}
		i++;
	}
	// segfaults fe end game
	return 0;
}

int animation(t_vars *vars)
{
	if(vars->e == find_exit(vars))
	{
		if(vars->z >= 0 && vars->z < 20)
			ft_render(vars, vars->wal1, vars->c1);
		if(vars->z >= 20 && vars->z < 40)
			ft_render(vars, vars->wal2, vars->c2);
		if(vars->z >= 40 && vars->z < 60)
		{
			ft_render(vars, vars->wal3, vars->c3);
			vars->z = 0;
		}
		vars->z++;
		mlx_string_put(vars->mlx, vars->win, 42, 30, 0xCE00FF, ft_itoa(vars->moves));
	}
	else
		end_game(vars);
	return 0;
}

void	norm54(t_vars *v, int *i, int j)
{
	mlx_string_put(v->mlx, v->win, 42, 30, 0xCE00FF, ft_itoa(v->moves));
	if (*i == 0 && j == 0)
	{
		mlx_put_image_to_window(v->mlx, v->win, v->a, 100 * *i, 50 * j);
		(*i)++;
	}
	else
		mlx_put_image_to_window(v->mlx, v->win, v->s, 50 * *i, 50 * j);
}
