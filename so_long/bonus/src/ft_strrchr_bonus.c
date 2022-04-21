/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_bouns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 15:56:24 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/21 05:15:39 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
