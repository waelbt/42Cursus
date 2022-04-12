/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:52:10 by waboutzo          #+#    #+#             */
/*   Updated: 2022/02/28 18:53:34 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

int		ft_atoi(const char *ptr);
void	handler(int signum);
int		ft_pow(int number, int force);
#endif
