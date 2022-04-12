/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:24:52 by waboutzo          #+#    #+#             */
/*   Updated: 2021/11/16 14:56:35 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
	{
		write(fd, "0", 1);
		write(fd, "\n", 1);
	}
	else
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
