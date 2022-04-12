/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:24:45 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/12 13:41:46 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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
