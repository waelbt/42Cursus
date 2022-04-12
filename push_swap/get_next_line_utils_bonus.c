/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 19:23:58 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 22:34:11 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = ft_strldup("", 0);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (NULL);
	while (s1[++i])
		p[j++] = s1[i];
	i = -1;
	while (s2[++i])
		p[j++] = s2[i];
	p[j] = '\0';
	free(s1);
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strldup(const char *s1, int len)
{
	char	*p;
	int		i;

	if (!s1)
		return (0);
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!p)
		return (NULL);
	while (s1[i] && i < len - 1)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	error(int i)
{
	if (i != 1)
		write(1, "Error\n", 6);
	return (0);
}
