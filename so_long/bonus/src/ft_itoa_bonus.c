/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:46:11 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/21 05:14:52 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	intlen(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*negative_n(int n, char *str)
{
	int				i;
	int				s;
	unsigned int	w;

	w = (unsigned int) n * (-1);
	s = intlen(n) + 1;
	i = s;
	str = (char *) malloc((s + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s > 1)
	{
		str[s - 1] = (w % 10) + '0';
		w = w / 10;
		s--;
	}
	str[0] = '-';
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		s;
	char	*str;

	str = NULL;
	if (n < 0)
	{
		str = negative_n(n, str);
	}
	else
	{
		s = intlen(n);
		i = s;
		str = (char *) malloc((s + 1) * sizeof(char));
		if (!str)
			return (0);
		while (s > 0)
		{
			str[s - 1] = (n % 10) + '0';
			n = n / 10;
			s--;
		}
		str[i] = '\0';
	}
	return (str);
}
