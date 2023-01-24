/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:27:22 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/23 16:17:46 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->next;
	stack->stack_data = stack->top;
}

void	rotate_both_stacks(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
}

void	reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}
