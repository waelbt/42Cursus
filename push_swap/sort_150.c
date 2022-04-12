/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_150.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:07:02 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 16:04:30 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	get_index(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->content > max)
		{
			a = a->next;
			i++;
		}
		if (a == NULL)
			return (i);
		if (a->content <= max && a->content >= min)
			return (i);
		i++;
		a = a->next;
	}
	return (-1);
}

void	chunks_sender(t_stack **a, t_stack **b, t_c *c)
{
	int	i;
	int	proximity;

	while (ft_lstsize(*b) != c->s)
	{
		i = get_index(*a, c->t[c->m], c->t[c->n]);
		proximity = ft_lstsize(*a) / 2;
		if (proximity > i)
		{
			while (i > 0)
			{
				rotate_stack(a, "ra");
				i = get_index(*a, c->t[c->m], c->t[c->n]);
			}
		}
		else
		{
			while (i > 0)
			{
				reverse_rotate_stack(a, "rra");
				i = get_index(*a, c->t[c->m], c->t[c->n]);
			}
		}
		sort_b(a, b, c->half);
	}
}

void	sort_b(t_stack **a, t_stack **b, int proximity)
{
	ft_push((*a)->content, b, a, "pb");
	if ((*b)->content <= proximity)
		rotate_stack(b, "rb");
}

void	math_time(t_c *c, int size)
{
	static int	y = 5;
	static int	x = 3;

	c->m = x * (size / 8);
	if (x != 0)
	{
		c->n = y * (size / 8);
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

void	arg_less_hundred(t_stack **a, t_stack **b)
{
	int	size;
	int	i;
	t_c	c;

	i = 0;
	size = ft_lstsize(*a);
	c.t = stack_to_array(*a);
	ft_sort_int_tab(c.t, size);
	c.half = c.t[size / 2];
	while (i < 4)
	{
		math_time(&c, size);
		chunks_sender(a, b, &c);
		i++;
	}
	c.s = ft_lstsize(*b);
	ft_home_comming(a, b, &c);
}
