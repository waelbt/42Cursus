/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_less_teen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 08:15:05 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 22:39:08 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	get_min_index(t_stack *a)
{
	int	stock;
	int	min;
	int	i;

	min = a->content;
	stock = 0;
	i = 0;
	while (a)
	{
		if (min > a->content)
		{
			min = a->content;
			stock = i;
		}
		a = a->next;
		i++;
	}
	return (stock);
}

int	get_max_index(t_stack *a)
{
	int	stock;
	int	min;
	int	i;

	min = a->content;
	stock = 0;
	i = 0;
	while (a)
	{
		if (min < a->content)
		{
			min = a->content;
			stock = i;
		}
		a = a->next;
		i++;
	}
	return (stock);
}

void	three_sort(t_stack **a)
{
	int	index[2];

	index[0] = get_min_index(*a);
	index[1] = get_max_index(*a);
	if (!ft_already_sorted(*a))
		return ;
	if (index[0] == 0)
	{
		swap_stack(a, "sa");
		rotate_stack(a, "ra");
	}
	else if (index[0] == 2)
	{
		if (index[1] == 0)
			swap_stack(a, "sa");
		reverse_rotate_stack(a, "rra");
	}
	else if (index[0] == 1)
	{
		if (index[1] == 2)
			swap_stack(a, "sa");
		if (index[1] == 0)
			rotate_stack(a, "ra");
	}
}

void	teen_sort(t_stack **a, t_stack **b)
{
	int	index[3];

	while (ft_lstsize(*a) > 3)
	{
		index[0] = get_min_index(*a);
		index[1] = ft_lstsize(*a) / 2;
		if (index[1] > index[0])
			rr(a, index[0]);
		else
			rra(a, index[0]);
		ft_push((*a)->content, b, a, "pb");
	}
	three_sort(a);
	index[2] = 0;
	while (*b)
	{
		ft_push((*b)->content, a, b, "pa");
		index[2]++;
	}
}
