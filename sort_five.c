/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:56:31 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 18:17:58 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*min;

	min = get_min(stack_a->top);
	while (1)
	{
		reindex_list(stack_a->stack_data);
		move_node_to_top(stack_a, min);
		if (check_sort(stack_a))
			break ;
		push_in_stack(stack_a, stack_b);
		min = get_min(stack_a->top);
		if (stack_a->size == 3)
			break ;
	}
	sort_three(stack_a);
	while (stack_b->stack_data)
		push_in_stack(stack_b, stack_a);
}
