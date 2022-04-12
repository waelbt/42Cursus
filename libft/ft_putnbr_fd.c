/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:37:30 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/18 15:31:47 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar_fd('-', fd);
		}	
		nbr = nb;
		if (nbr >= 10)
		{
			ft_putnbr_fd((nbr / 10), fd);
		}
		ft_putchar_fd((nbr % 10 + '0'), fd);
	}
}
