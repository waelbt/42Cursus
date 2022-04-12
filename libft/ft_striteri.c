/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:32:38 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/19 02:29:39 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void fi(unsigned int i, char *c)
{
	*c += i;
}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}

/*
int main(void)
{
	char str[] = "hello";
	void (*f)(unsigned int, char *) = fi;
	ft_striteri(str,f);
	printf("%s",str);
}
*/
