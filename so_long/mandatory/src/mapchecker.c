/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapchecker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 08:41:25 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/12 13:47:54 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
			&& str[j] != 'P')
			return (0);
		j++;
	}
	return (1);
}

void	content_counter(char *str, t_vars *a)
{
	int		i;
	t_vars	b;

	i = 0;
	b.c = 0;
	b.e = 0;
	b.p = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			b.p += 1;
		if (str[i] == 'C')
			b.c += 1;
		if (str[i] == 'E')
			b.e += 1;
		i++;
	}
	a->c += b.c;
	a->p += b.p;
	a->e += b.e;
}

int	ft_check(t_vars *dim)
{
	int		i;

	i = 1;
	dim->c = 0;
	dim->e = 0;
	dim->p = 0;
	if (!wall_check(dim->matrix[0], dim))
		return (0);
	while (i < (dim->height - 1))
	{
		if (ft_strlen(dim->matrix[i]) != dim->width || dim->matrix[i][0] != '1'
			|| dim->matrix[i][dim->width - 1] != '1'
				|| !stranger_check(dim->matrix[i]))
			return (0);
		content_counter(dim->matrix[i], dim);
		i++;
	}
	if (dim->c < 1 || dim->p != 1 || dim->e < 1
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
