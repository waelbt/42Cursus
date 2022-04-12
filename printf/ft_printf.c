/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:51:01 by waboutzo          #+#    #+#             */
/*   Updated: 2021/12/07 16:08:10 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char c, va_list args)
{
	char	*base;

	base = "0123456789abcdef";
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (2 + ft_putnbr_base(va_arg(args, unsigned long long), base));
	}
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int), base));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *s, ...)
{
	int		len;
	int		count;
	va_list	args;

	len = 0;
	count = 0;
	va_start(args, s);
	while (s[count])
	{
		if (s[count] != '%')
		{
			ft_putchar(s[count]);
			len++;
		}
		else
		{
			count++;
			len = len + ft_check(s[count], args);
		}
		count++;
	}
	va_end(args);
	return (len);
}
