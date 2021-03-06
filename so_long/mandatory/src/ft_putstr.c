/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:13:33 by waboutzo          #+#    #+#             */
/*   Updated: 2022/04/10 15:10:18 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
