/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:50:45 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/19 16:55:26 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
