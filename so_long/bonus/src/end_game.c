/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:19:41 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/14 19:49:02 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bouns.h"

int	end_game(t_vars *vars)
{
	static int i;
	static int j;

	if(vars->e != find_exit(vars))
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
			vars->e = 0;
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
	static int z;

	(void)z;
	if(z >= 0 && z < 10000)
		ft_render(vars, vars->wal3, vars->c3);
	if(z > 10000 && z < 20000)
		ft_render(vars, vars->wal1, vars->c1);
	if(z > 20000 && z < 30000)
	{
		ft_render(vars, vars->wal2, vars->c2);
		z = 0;
	}
	z++;
	return 0;
}