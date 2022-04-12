/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waboutzo <waboutzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:15 by waboutzo          #+#    #+#             */
/*   Updated: 2022/03/28 15:56:44 by waboutzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../get_next_line_bonus.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct c
{
	int	m;
	int	n;
	int	*t;
	int	s;
	int	half;
	int	down;
	int	proximity;
	int	index;
	int	i;
}	t_c;

int		ft_check_isdigit(char *str);
int		ft_already_sorted(t_stack *a);
void	ft_push(int num, t_stack **a, t_stack **b, char *str);
int		ft_is_duplicate(t_stack *a);
void	swap_stack(t_stack **a, char *str);
void	rotate_stack(t_stack **a, char *str);
void	reverse_rotate_stack(t_stack **a, char *str);
void	printflinklist(t_stack *head);
int		*stack_to_array(t_stack *a);
void	ft_sort_int_tab(int *tab, int size);
void	printf_array(int *t, int size);
void	ft_push_chunks(t_stack **a, t_stack **b, int *t, int max);
int		get_index(t_stack *a, int min, int max);
void	chunks_sender(t_stack **a, t_stack **b, t_c *c);
void	rr(t_stack **a, int index);
void	rra(t_stack **a, int index);
void	arg_less_hundred(t_stack **a, t_stack **b);
void	teen_sort(t_stack **a, t_stack **b);
int		get_min_index(t_stack *a);
int		get_max_index(t_stack *a);
void	three_sort(t_stack **a);
void	arg_upper_hundred(t_stack **a, t_stack **b);
void	sort_b(t_stack **a, t_stack **b, int proximity);
void	ft_home_comming(t_stack **a, t_stack **b, t_c *c);
int		ft_strlon(char **str);
int		norm_131(char **str, t_stack **a);
int		norm_82(char *str);
int		ft_msg(void);
#endif
