/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:28 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/02 11:21:36 by aamhamdi         ###   ########.fr       */
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
	t_list *tmp;
	
	node = creat_node(data, stack->size);
	if(!stack->top)
		stack->top = node;
	else
	{
		if(stack->size == 1)
		{
			node->next = stack->top;
			node->prev = stack->top;
			stack->top->next = node;
			stack->top->prev = node;
			stack->top = node;
		}
		else{
			tmp = stack->top->prev;
			stack->top->prev = node;
			node->next = stack->top;
			node->prev = tmp;
			tmp->next = node;
			stack->top = node;
		}
	}
	stack->stack_data = stack->top;
}

void pop(t_stack *stack)
{
	t_list *tmp;

	stack->top->prev->next = stack->top->next;
	stack->top->next->prev = stack->top->prev;
	tmp = stack->top->next;
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
	from->size--;
	to->size++;
	pop(from);
}

t_list *get_last_node(t_list *list)
{
	t_list *tmp;

	tmp = list;
	while(tmp->next)
	{
		tmp =tmp->next;
	}
	return tmp;
}


void rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->next;
	stack->stack_data = stack->top;
}

void rotate_both_stacks(t_stack *a, t_stack *b)
{
    rotate_stack(a);
    rotate_stack(b);
}

void reverse_rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
}

void reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
    reverse_rotate_stack(a);
    reverse_rotate_stack(b);
}