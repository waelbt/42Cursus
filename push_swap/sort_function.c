/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:39:02 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 21:16:51 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	swap_stack(t_stack **a, char *str)
{
	t_stack	*tmp;
	int		stock;

	if (*a && ft_lstsize(*a) > 1)
	{
		tmp = (*a)->next;
		stock = (*a)->content;
		(*a)->content = tmp->content;
		tmp->content = stock;
		if (str)
			ft_putstr(str);
	}
}

void	rotate_stack(t_stack **a, char *str)
{
	t_stack	*tmp;

	if (*a && ft_lstsize(*a) > 1)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_back(a, tmp);
		if (str)
			ft_putstr(str);
	}
}

void	reverse_rotate_stack(t_stack **a, char *str)
{
	t_stack	*tmp;
	t_stack	*b;
	int		i;

	i = 0;
	tmp = *a;
	if (*a && ft_lstsize(*a) > 1)
	{
		while (tmp->next->next)
		{
			tmp = tmp->next;
		}
		b = tmp->next;
		tmp->next = NULL;
		ft_lstadd_front(a, b);
		if (str)
			ft_putstr(str);
	}
}

void	rr(t_stack **a, int index)
{
	while (index > 0)
	{
		rotate_stack(a, "ra");
		index = get_min_index(*a);
	}
}

void	rra(t_stack **a, int index)
{
	while (index > 0)
	{
		reverse_rotate_stack(a, "rra");
		index = get_min_index(*a);
	}
}
