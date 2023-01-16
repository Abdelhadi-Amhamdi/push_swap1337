/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:28 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/16 17:42:28 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (!stack->top)
		return ;
	tmp = stack->top->list_data;
	stack->top->list_data = stack->stack_data->next->list_data;
	stack->top->next->list_data = tmp;
	write(1, "s", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	swap_both_stacks(t_stack *b, t_stack *a)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 2);
}

void	push_in_stack(t_stack *from, t_stack *to)
{
	t_list	*tmp;
	t_list	*item;

	item = from->stack_data;
	tmp = item->next;
	make_list_not_circular(to);
	make_list_not_circular(from);
	item->next = NULL;
	item->prev = NULL;
	if (to->stack_data)
	{
		item->next = to->stack_data;
		to->stack_data->prev = item;
	}
	to->stack_data = item;
	to->top = item;
	tmp->prev = NULL;
	from->stack_data = tmp;
	from->top = tmp;
	to->size++;
	from->size--;
	if (to->size == 0)
		to->stack_data = NULL;
	if (from->size == 0)
		from->stack_data = NULL;
	make_list_circular(to);
	make_list_circular(from);
	write(1, "p", 1);
	write(1, &to->name, 1);
	write(1, "\n", 1);
}

void	rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->next;
	stack->stack_data = stack->top;
	write(1, "r", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	rotate_both_stacks(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}

void	reverse_rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
	write(1, "rr", 2);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}
