/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:30:44 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/19 16:56:11 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 == *s2 && *s1 && *s2 && i <= n)
	{
		i++;
		s1++;
		s2++;
	}
	if (i != n)
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (0);
}
