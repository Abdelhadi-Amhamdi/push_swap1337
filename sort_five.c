/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:56:31 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 15:56:44 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_list *min;

	min = get_min(stack_a->top);
	while (1)
	{
		if (stack_a->top->list_data == min->list_data)
		{
			push_in_stack(stack_a, stack_b);
			min = get_min(stack_a->top);
		}
		else
		{
			if (min->index + 1 < (stack_a->size + 1) / 2)
				reverse_rotate_stack(stack_a);
			else
				rotate_stack(stack_a);
		}
		if (stack_a->size == 3)
			break;
	}
	sort_three(stack_a);
	while (stack_b->stack_data)
		push_in_stack(stack_b, stack_a);
}