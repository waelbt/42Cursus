/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 02:24:28 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/27 22:12:06 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_check_isdigit(char *str)
{
	int	i;

	i = 0;
	if (ft_strcmp(str, "") == 0)
		return (0);
	if (str[0] == '-')
	{
		i = 1;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_already_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a->next;
	while (tmp)
	{
		if (a->content > tmp->content)
			return (1);
		a = a->next;
		tmp = tmp->next;
	}
	return (0);
}

int	ft_is_duplicate(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		a = tmp->next;
		while (a)
		{
			if (tmp->content == a->content)
				return (0);
			a = a->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	*stack_to_array(t_stack *a)
{
	int	*t;
	int	i;

	i = 0;
	t = (int *) malloc(ft_lstsize(a) * sizeof(int));
	while (a)
	{
		t[i] = a->content;
		a = a->next;
		i++;
	}
	return (t);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	z;
	int	i;
	int	stock;

	i = 0;
	while (i < size)
	{
		z = 0;
		while (i + z < size)
		{
			if (tab[i] > tab[i + z])
			{
				stock = tab[i];
				tab[i] = tab[i + z];
				tab[i + z] = stock;
			}
			z++;
		}
		i++;
	}
}
