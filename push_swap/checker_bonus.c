/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:19:45 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/28 15:54:15 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	ft_strlon(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	norm(t_stack ***a, t_stack ***b, char *str)
{
	if (ft_strcmp(str, "rb") == 0)
		rotate_stack(*b, NULL);
	else if (ft_strcmp(str, "rra") == 0)
		reverse_rotate_stack(*a, NULL);
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate_stack(*b, NULL);
	else if (ft_strcmp(str, "rrr") == 0)
	{
		reverse_rotate_stack(*a, NULL);
		reverse_rotate_stack(*b, NULL);
	}
	else if (ft_strcmp(str, "rr") == 0)
	{
		rotate_stack(*a, NULL);
		rotate_stack(*b, NULL);
	}
	else if (ft_strcmp(str, "ss") == 0)
	{
		swap_stack(*a, NULL);
		swap_stack(*b, NULL);
	}
	else
		return (0);
	return (1);
}

int	instruction_execution(t_stack **a, t_stack **b, char *str)
{
	if (!norm(&a, &b, str))
	{
		if (ft_strcmp(str, "sa") == 0)
			swap_stack(a, NULL);
		else if (ft_strcmp(str, "sb") == 0)
			swap_stack(b, NULL);
		else if (ft_strcmp(str, "pa") == 0)
			ft_push((*b)->content, a, b, NULL);
		else if (ft_strcmp(str, "pb") == 0)
			ft_push((*a)->content, b, a, NULL);
		else if (ft_strcmp(str, "ra") == 0)
			rotate_stack(a, NULL);
		else
			return (0);
	}
	return (1);
}

int	check(t_stack **a)
{
	char	*str;
	t_stack	*b;

	b = NULL;
	if (!ft_is_duplicate(*a))
		return (error(2));
	str = get_next_line(0);
	while (str)
	{
		if (!instruction_execution(a, &b, str))
		{
			printf("Error");
			return (0);
		}
		str = get_next_line(0);
	}
	if (b == NULL && !ft_already_sorted(*a))
		printf("OK");
	else
		printf("KO");
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i[2];
	char	**str;

	a = NULL;
	if (argc > 2)
	{
		i[0] = argc;
		while (--i[0] > 0)
		{
			i[1] = -1;
			if (ft_strcmp(argv[i[0]], "") == 0)
				return (error(0));
			str = ft_split(argv[i[0]], 32);
			if (norm_131(str, &a) == 0)
				return (0);
		}
		check(&a);
	}
	else
		error(argc);
	return (0);
}
