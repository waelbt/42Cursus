/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendre_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:10:45 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/03 18:08:37 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	initialise_images(t_vars *v, char *e)
{
	int		w;
	int		h;
	char	*str;

	str = ft_strjoin("assets/E/", e);
	v->assests.frame3 = mlx_xpm_file_to_image(v->mlx, str, &w, &h);
	free(str);
	v->assests.frame2 = mlx_xpm_file_to_image(v->mlx, "assets/P/1.xpm", &w, &h);
	v->wall.frame1 = mlx_xpm_file_to_image(v->mlx, "assets/W/1.xpm", &w, &h);
	v->count.frame1 = mlx_xpm_file_to_image(v->mlx, "assets/W/c1.xpm", &w, &h);
	v->wall.frame2 = mlx_xpm_file_to_image(v->mlx, "assets/W/2.xpm", &w, &h);
	v->count.frame2 = mlx_xpm_file_to_image(v->mlx, "assets/W/c2.xpm", &w, &h);
	v->wall.frame3 = mlx_xpm_file_to_image(v->mlx, "assets/W/3.xpm", &w, &h);
	v->count.frame3 = mlx_xpm_file_to_image(v->mlx, "assets/W/c3.xpm", &w, &h);
	v->assests.frame1 = mlx_xpm_file_to_image(v->mlx, "assets/C/1.xpm", &w, &h);
	v->bg = mlx_xpm_file_to_image(v->mlx, "assets/O/1.xpm", &w, &h);
	v->enemy.frame1 = mlx_xpm_file_to_image(v->mlx, "assets/H/1.xpm", &w, &h);
	v->enemy.frame2 = mlx_xpm_file_to_image(v->mlx, "assets/H/2.xpm", &w, &h);
	v->enemy.frame3 = mlx_xpm_file_to_image(v->mlx, "assets/H/3.xpm", &w, &h);
	v->angry.frame1 = mlx_xpm_file_to_image(v->mlx, "assets/H/1_1.xpm", &w, &h);
	v->angry.frame2 = mlx_xpm_file_to_image(v->mlx, "assets/H/2_2.xpm", &w, &h);
	v->angry.frame3 = mlx_xpm_file_to_image(v->mlx, "assets/H/3_3.xpm", &w, &h);
}

void	ft_render(t_vars *v, void *s, void *c)
{
	int	i[2];

	i[1] = -1;
	while (++i[1] < v->height)
	{
		i[0] = -1;
		while (++i[0] < v->width)
		{
			if (v->matrix[i[1]][i[0]] == '1')
			{
				mlx_string_put(v->mlx, v->win, 42,
					30, 0xCE00FF, ft_itoa(v->moves));
				if (i[0] == 0 && i[1] == 0)
					mlx_put_image_to_window(v->mlx, v->win, c,
						100 * i[0]++, IMG_SIZE * i[1]);
				else
					mlx_put_image_to_window(v->mlx, v->win, s,
						IMG_SIZE * i[0], IMG_SIZE * i[1]);
			}
			else if (v->matrix[i[1]][i[0]] == '0')
				mlx_put_image_to_window(v->mlx, v->win,
					v->bg, IMG_SIZE * i[0], IMG_SIZE * i[1]);
			norm54(v, i[0], i[1]);
		}
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
