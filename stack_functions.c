/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:28 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/26 16:14:20 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_empty(t_stack *stack)
{
    return (stack->top != 0);
}

void push(t_stack *stack, int data)
{
	t_list *node;
	t_list *my_list;

	my_list = stack->stack_data;
	node = creat_node(data);
	if(!my_list)
		my_list = node;
	else
		insert_node(&my_list, node);
	stack->top = node;
	stack->size++;
	stack->stack_data = my_list;
}

void pop(t_stack *stack)
{
	t_list *tmp;

	tmp = stack->stack_data->next;

	free(stack->top);
	stack->top = tmp;
	stack->stack_data = tmp;
}


void swap_stack(t_stack *stack)
{
	int tmp;
	if(!stack->top)
		return;
	tmp = stack->top->list_data;
	stack->top->list_data = stack->stack_data->next->list_data;
	stack->top->next->list_data = tmp;
}

void swap_both_stacks(t_stack *b , t_stack *a)
{
	swap_stack(a);
	swap_stack(b);
}

void push_in_stack(t_stack *from , t_stack *to)
{
	push(to, from->stack_data->list_data);
	pop(from);
}

t_list *get_last_node(t_list *list)
{
	while(list->next)
		list = list->next;
	return list;
}


void rotate_stack(t_stack *stack)
{
	t_list *last;
	
	stack->stack_data = stack->top->next;
	stack->top->next = 0;
	last = get_last_node(stack->stack_data);
	last->next = stack->top;
}

void rotate_both_stacks(t_stack *a, t_stack *b)
{
    rotate_stack(a);
    rotate_stack(b);
}

void reverse_rotate_stack(t_stack *stack)
{
	t_list *last;

	last = get_last_node(stack->stack_data);
	last->prev->next = NULL;
	stack->stack_data = last;
	last->next = stack->top;
}

void reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
    reverse_rotate_stack(a);
    reverse_rotate_stack(b);
}