/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:44:48 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/17 21:02:30 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char fun(unsigned int i, char c)
{
	return c + i;
}
*/
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		c;
	int		i;

	i = 0;
	if (!s)
		return (0);
	c = ft_strlen(s);
	p = (char *) malloc((c + 1) * sizeof(char));
	if (!p)
		return (0);
	while (i < c)
	{
		p[i] = f(i, (char )(s[i]));
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*
int main(void)
{
	char (*f)(unsigned int, char) = fun;
	char str[] = "hello";
	printf("%s",ft_strmapi(str, f));
}
*/
