/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:16 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/12 13:49:20 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	key_management(int keycode, t_vars *vars)
{
	static int	i = 0;

	if (keycode == 53 || keycode < 0)
		exit(0);
	else
	{
		i++;
		moves(vars, keycode);
		ft_putstr("moves number: ");
		ft_putnbr(i);
		ft_putstr("\n");
	}
	ft_render(vars);
	return (0);
}

int	main(int argc,	char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber"))
			error("error Invalid file");
		ft_dimension(argv[1], &vars);
		ft_matrix(argv[1], &vars);
		if (!check_end_of_file(argv[1], &vars) || !ft_check(&vars))
			error("error Invalid Map");
		vars.wi = 50 * vars.width;
		vars.he = 50 * vars.height;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, vars.wi, vars.he, "Hello world!");
		initialise_images(&vars, "1.xpm", "1.xpm", "1.xpm");
		ft_render(&vars);
		mlx_hook(vars.win, 2, 0, key_management, &vars);
		mlx_hook(vars.win, 17, 0, key_management, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
