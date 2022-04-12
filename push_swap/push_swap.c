/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:09:48 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/28 16:01:12 by waboutzo         ###   ########.fr       */
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

int	ft_msg(void)
{
	write(1, "Error\n", 6);
	return (0);
}

int	norm_42(t_stack **a)
{
	t_stack	*b;
	int		len;

	b = NULL;
	len = ft_lstsize(*a);
	if (!ft_is_duplicate(*a))
		return (ft_msg());
	if (!ft_already_sorted(*a))
		return (0);
	len = ft_lstsize(*a);
	if (len <= 10)
		teen_sort(a, &b);
	else if (len <= 150)
		arg_less_hundred(a, &b);
	else if (len > 150)
		arg_upper_hundred(a, &b);
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
			str = ft_split(argv[i[0]], 32);
			while (++i[1] < ft_strlon(str))
			{
				if (!norm_82(str[i[1]]))
					return (0);
				ft_push(ft_atoi(str[i[1]]), &a, NULL, NULL);
				free(str[i[1]]);
			}
			free(str);
		}
		norm_42(&a);
	}
	return (0);
}
