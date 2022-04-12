/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:07:27 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/27 15:37:48 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char )c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[] = "tripouille";
	printf("%s \n",ft_strchr(s, 't' + 256));
	printf("%s",strchr(s, 't' + 256));
}
*/