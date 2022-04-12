/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:59:07 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 16:04:37 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	find_number(int max, t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		if (max == a->content)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int	get_tail(t_stack *a)
{
	while (a->next)
	{
		a = a->next;
	}
	return (a->content);
}

void	ft_norm(t_stack **a, t_stack **b, t_c *c)
{
	if (c->index == 0)
	{
		ft_push((*b)->content, a, b, "pa");
		c->i++;
	}
	else
	{
		if (c->down == 0 || (*b)->content > get_tail(*a))
		{
			ft_push((*b)->content, a, b, "pa");
			rotate_stack(a, "ra");
			c->down++;
		}
		else
		{
			if (c->index < c->half)
				rotate_stack(b, "rb");
			else
				reverse_rotate_stack(b, "rrb");
		}
	}
}

void	ft_home_comming(t_stack **a, t_stack **b, t_c *c)
{
	c->i = 1;
	c->down = 0;
	while (ft_lstsize(*b))
	{
		c->index = find_number(c->t[c->s - c->i], *b);
		c->half = ft_lstsize(*b) / 2;
		if (c->index != -1)
			ft_norm(a, b, c);
		else
		{
			if (ft_lstsize(*a) != 0 && c->down)
			{
				reverse_rotate_stack(a, "rra");
				c->down--;
				c->i++;
			}
		}
	}
	while (c->down)
	{
		reverse_rotate_stack(a, "rra");
		c->down--;
	}
}
