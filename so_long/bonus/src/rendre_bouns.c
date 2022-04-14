/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendre_bouns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:10:45 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/14 17:46:29 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bouns.h"

void	initialise_images(t_vars *v, char *e)
{
	int		wid;
	int		hei;
	char	*str;

	str = ft_strjoin("assets/exit/", e);
	v->exi = mlx_xpm_file_to_image(v->mlx, str, &wid, &hei);
	free(str);
	v->pla = mlx_xpm_file_to_image(v->mlx, "assets/player/1.xpm", &wid, &hei);
	v->wal1 = mlx_xpm_file_to_image(v->mlx, "assets/wall/1.xpm", &wid, &hei);
	v->c1 = mlx_xpm_file_to_image(v->mlx, "assets/wall/1_counter.xpm", &wid, &hei);
	v->wal2 = mlx_xpm_file_to_image(v->mlx, "assets/wall/2.xpm", &wid, &hei);
	v->c2 = mlx_xpm_file_to_image(v->mlx, "assets/wall/2_counter.xpm", &wid, &hei);
	v->wal3 = mlx_xpm_file_to_image(v->mlx, "assets/wall/3.xpm", &wid, &hei);
	v->c3 = mlx_xpm_file_to_image(v->mlx, "assets/wall/3_counter.xpm", &wid, &hei);
	v->col = mlx_xpm_file_to_image(v->mlx, "assets/c/1.xpm", &wid, &hei);
	v->bg = mlx_xpm_file_to_image(v->mlx, "assets/bg/1.xpm", &wid, &hei);
}

void	ft_render(t_vars *v, void *s, void *c)
{
	int	i;
	int	j;

	j = 0;
	while (j < v->height)
	{
		i = 0;
		while (i < v->width)
		{
			if (v->matrix[j][i] == 'C')
				mlx_put_image_to_window(v->mlx, v->win, v->col, 50 * i, 50 * j);
			else if (v->matrix[j][i] == 'P')
				mlx_put_image_to_window(v->mlx, v->win, v->pla, 50 * i, 50 * j);
			else if (v->matrix[j][i] == 'E')
				mlx_put_image_to_window(v->mlx, v->win, v->exi, 50 * i, 50 * j);
			else if (v->matrix[j][i] == '1')
			{
				if(i == 0 && j == 0)
				{
					mlx_put_image_to_window(v->mlx, v->win, c, 100 * i, 50 * j);
					i++;
				}
				else
					mlx_put_image_to_window(v->mlx, v->win, s, 50 * i, 50 * j);
			}
			else
				mlx_put_image_to_window(v->mlx, v->win, v->bg, 50 * i, 50 * j);
			i++;
		}
		j++;
	}
}

void	ft_dimension(char *str, t_vars *dim)
{
	int		fd;
	char	*ptr;

	ptr = NULL;
	dim->height = 0;
	fd = open(str, 0);
	if (fd < 0)
		error("error Invalid file");
	ptr = get_next_line(fd);
	dim->width = ft_strlen(ptr) - 1;
	while (ptr)
	{
		dim->height++;
		free(ptr);
		ptr = get_next_line(fd);
	}
	free(ptr);
	close(fd);
}

void	ft_matrix(char *str,	t_vars *dim)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(str, 0);
	if (fd < 0)
		error("error Invalid file");
	dim->matrix = (char **) malloc(dim->height * sizeof(char *));
	while (i < dim->height)
	{
		dim->matrix[i] = get_next_line(fd);
		dim->matrix[i][dim->width] = '\0';
		i++;
	}
	close(fd);
}

int	charcmp(char c, char i, char j)
{
	if (c != i && c != j)
		return (1);
	return (0);
}