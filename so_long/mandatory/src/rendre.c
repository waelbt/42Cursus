/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:02:45 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/05 16:02:46 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialise_images(t_vars *v, char *e)
{
	int		w;
	int		h;
	char	*str;

	str = ft_strjoin("assets/E/", e);
	v->assets.exit = mlx_xpm_file_to_image(v->mlx, str, &w, &h);
	free(str);
	v->assets.pla = mlx_xpm_file_to_image(v->mlx, "assets/P/1.xpm", &w, &h);
	v->assets.wall = mlx_xpm_file_to_image(v->mlx, "assets/wall/1.xpm", &w, &h);
	v->assets.col = mlx_xpm_file_to_image(v->mlx, "assets/C/1.xpm", &w, &h);
	v->assets.bg = mlx_xpm_file_to_image(v->mlx, "assets/O/1.xpm", &w, &h);
}

void	ft_render(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < v->height)
	{
		i = 0;
		while (i < v->width)
		{
			norm(v, i, j);
			if (v->matrix[j][i] == '1')
				mlx_put_image_to_window(v->mlx, v->win, v->assets.wall,
					IMG_SIZE * i, IMG_SIZE * j);
			else if (v->matrix[j][i] == '0')
				mlx_put_image_to_window(v->mlx, v->win, v->assets.bg,
					IMG_SIZE * i, IMG_SIZE * j);
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
