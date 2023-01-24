/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:38:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 17:49:34 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (!stack->stack_data)
		return ;
	tmp = stack->top->list_data;
	stack->top->list_data = stack->stack_data->next->list_data;
	stack->top->next->list_data = tmp;
}

void	swap_both_stacks(t_stack *b, t_stack *a)
{
	if (!b->stack_data || !a->stack_data)
		return ;
	swap_stack(a);
	swap_stack(b);
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*tmp;
	t_list	*item;

	item = from->stack_data;
	tmp = item->next;
	item->next = NULL;
	item->prev = NULL;
	if (to->size)
	{
		item->next = to->stack_data;
		to->stack_data->prev = item;
	}
	to->stack_data = item;
	to->top = item;
	if (tmp)
		tmp->prev = NULL;
	from->stack_data = tmp;
	from->top = tmp;
}

void	push_in_stack(t_stack *from, t_stack *to)
{
	if (!from->stack_data || !to->stack_data)
		return ;
	make_list_not_circular(to);
	make_list_not_circular(from);
	push(from, to);
	to->size++;
	from->size--;
	if (to->size == 0)
		to->stack_data = NULL;
	if (from->size == 0)
		from->stack_data = NULL;
	make_list_circular(to);
	make_list_circular(from);
}
