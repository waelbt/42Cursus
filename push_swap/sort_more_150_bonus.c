/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_150.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:49:27 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 22:12:24 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	math_time_0(t_c *c, int size)
{
	static int	y = 10;
	static int	x = 8;

	c->m = x * (size / 18);
	if (x != 0)
	{
		c->n = y * (size / 18);
		c->s = c->n - c->m + 1;
	}
	else
	{
		c->n = size - 1;
		c->s = c->n + 1;
	}
	y++;
	x--;
}

void	arg_upper_hundred(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	t_c	c;

	i = 0;
	size = ft_lstsize(*a);
	c.t = stack_to_array(*a);
	ft_sort_int_tab(c.t, size);
	c.half = c.t[size / 2];
	while (i < 9)
	{
		math_time_0(&c, size);
		chunks_sender(a, b, &c);
		i++;
	}
	size = ft_lstsize(*b);
	ft_home_comming(a, b, &c);
}

void	ft_push(int num, t_stack **a, t_stack **b, char *str)
{
	t_stack	*new;

	if (b != NULL)
	{
		new = *b;
		*b = (*b)->next;
		free(new);
		if (str)
			ft_putstr(str);
	}
	new = ft_lstnew(num);
	ft_lstadd_front(a, new);
}
