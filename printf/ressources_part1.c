/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ressources_part1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:50:01 by waboutzo          #+#    #+#             */
/*   Updated: 2021/12/06 21:30:40 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return (ft_strlen(s));
	}
	write(1, "(null)", 6);
	return (6);
}

int	ft_putnbr(int nb)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = nb;
	if (nb < 0)
	{
		nbr = nb * (-1);
		count += ft_putchar('-');
	}
	if (nbr >= 10)
	{
		count += ft_putnbr(nbr / 10);
		return (count += ft_putchar(nbr % 10 + '0'));
	}
	return (count += ft_putchar(nbr % 10 + '0'));
}

int	ft_putnbr_base(unsigned long long nb, char *base)
{
	unsigned long long	len_base;
	int					count;

	count = 0;
	len_base = ft_strlen(base);
	if (nb >= len_base)
	{
		count += ft_putnbr_base(nb / len_base, base);
	}
	return (count += ft_putchar(base[nb % len_base]));
}
