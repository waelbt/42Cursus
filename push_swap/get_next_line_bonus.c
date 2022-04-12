/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:26:39 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/28 15:49:10 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

char	*get_line(char *s1, int rd)
{
	int		i;
	char	*p;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	p = ft_strldup(s1, i + 1);
	if (rd == 0 && ft_strlen(p) == 0)
	{
		free(p);
		return (NULL);
	}
	return (p);
}

char	*get_remember(char *s1)
{
	int		i;
	char	*p;

	i = 0;
	if (!s1)
		return (0);
	if (s1[0] == '\0')
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\0' && s1[i] != '\n')
		i++;
	i++;
	p = ft_strldup(s1 + i, ft_strlen(s1) - i + 1);
	free(s1);
	return (p);
}

char	*ft_free(char *buffer)
{
	free(buffer);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*save;
	int				rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rd = 1;
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[0] = '\0';
	while (rd != 0 && !ft_strchr(buffer, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
			return (ft_free(buffer));
		buffer[rd] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	line = get_line(save, rd);
	save = get_remember(save);
	return (line);
}

int	norm_131(char **str, t_stack **a)
{
	int	i;

	i = -1;
	while (++i < ft_strlon(str))
	{
		if (!ft_check_isdigit(str[i]))
			return (error(0));
		if (!(ft_atoi(str[i]) >= INT_MIN
				&& ft_atoi(str[i]) <= INT_MAX))
			return (error(0));
		ft_push(ft_atoi(str[i]), a, NULL, NULL);
		free(str[i]);
	}
	free(str);
	return (1);
}
