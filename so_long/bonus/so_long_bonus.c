/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:53:16 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/04 00:50:30 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long_bonus.h"

void	error(char *str)
{
	ft_putstr(str);
	exit(1);
}

int	inputs(int keycode, t_vars *vars)
{
	if (keycode == 53 || keycode < 0)
		exit(0);
	else
		moves(vars, keycode);
	animation(vars);
	return (0);
}

int	main(int argc,	char **argv)
{
	t_vars	vars;

	vars.moves = 0;
	vars.counter = 0;
	if (argc == 2)
	{
		if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber"))
			error("error Invalid file\n");
		ft_dimension(argv[1], &vars);
		ft_matrix(argv[1], &vars);
		if (!check_end_of_file(argv[1], &vars) || !ft_check(&vars))
			error("error Invalid Map\n");
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, IMG_SIZE * vars.width,
				IMG_SIZE * vars.height, "Hello world!");
		initialise_images(&vars, "1.xpm");
		animation(&vars);
		mlx_key_hook(vars.win, inputs, &vars);
		mlx_hook(vars.win, 17, 0, inputs, &vars);
		mlx_loop_hook(vars.mlx, animation, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
