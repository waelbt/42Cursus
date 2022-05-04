/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 08:41:25 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/03 17:29:48 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	wall_check(char *str, t_vars *dim)
{
	int	i;

	i = 0;
	while (i < dim->width)
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	stranger_check(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (str[j] != '1' && str[j] != 'E'
			&& str[j] != '0' && str[j] != 'C'
			&& str[j] != 'P' && str[j] != 'H')
			return (0);
		j++;
	}
	return (1);
}

void	content_counter(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	v->collects_counter = 0;
	v->exit_counter = 0;
	v->player_counter = 0;
	while (j < v->height)
	{
		i = 0;
		while (i < v->width)
		{
			if (v->matrix[j][i] == 'P')
				v->player_counter += 1;
			else if (v->matrix[j][i] == 'C')
				v->collects_counter += 1;
			else if (v->matrix[j][i] == 'E')
				v->exit_counter += 1;
			else if (v->matrix[j][i] == 'H')
				v->enemy_counter += 1;
			i++;
		}
		j++;
	}
}

int	ft_check(t_vars *dim)
{
	int		i;

	i = 1;
	if (!wall_check(dim->matrix[0], dim))
		return (0);
	while (i < (dim->height - 1))
	{
		if (ft_strlen(dim->matrix[i]) != dim->width || dim->matrix[i][0] != '1'
			|| dim->matrix[i][dim->width - 1] != '1'
				|| !stranger_check(dim->matrix[i]))
			return (0);
		i++;
	}
	content_counter(dim);
	if (dim->collects_counter < 1 || dim->player_counter != 1
		|| dim->exit_counter < 1
		|| !wall_check(dim->matrix[dim->height - 1], dim)
		|| (ft_strlen(dim->matrix[dim->height - 1]) != dim->width))
		return (0);
	return (1);
}

int	check_end_of_file(char *str, t_vars *dim)
{
	int		fd;
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	fd = open(str, 0);
	if (fd < 0)
		return (0);
	while (i < dim->height - 1)
	{
		ptr = get_next_line(fd);
		free(ptr);
		i++;
	}
	ptr = get_next_line(fd);
	if (ptr && ptr[dim->width] == '\n')
		return (0);
	free(ptr);
	return (1);
}
