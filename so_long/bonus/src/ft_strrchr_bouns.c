/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_bouns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:56:24 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/13 15:52:18 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bouns.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen((char *) s);
	c = (char) c;
	while (len > 0)
	{
		if (*(s + len) == (char) c)
			return ((char *)(s + len));
		len--;
	}
	if (*(char *)(s + len) == c)
		return ((char *) s);
	return (0);
}
