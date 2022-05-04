/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:51:52 by waboutzo          #+#    #+#             */
/*   Updated: 2022/05/03 18:44:35 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
