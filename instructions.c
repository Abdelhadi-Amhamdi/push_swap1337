/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:28 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/13 17:10:58 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <assert.h>

void push(t_stack *stack, t_list *data)
{
	t_list *node;
	t_list *tmp;
	
	node = data;
	if(!stack->stack_data)
	{
		stack->stack_data = node;
		stack->stack_data->prev = node;
		stack->stack_data->next = node;
		stack->top = stack->stack_data;
	}
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
	if(stack->stack_data == stack->stack_data->prev)
	{
		free(stack->top);
		stack->top = NULL;
		stack->stack_data = NULL;
	}else{
		stack->top->prev->next = stack->top->next;
		stack->top->next->prev = stack->top->prev;
		tmp = stack->top->next;
		free(stack->top);
		stack->top = tmp;
		stack->stack_data = tmp;
	}
}


void swap_stack(t_stack *stack)
{
	int tmp;
	if(!stack->top)
		return;
	tmp = stack->top->list_data;
	stack->top->list_data = stack->stack_data->next->list_data;
	stack->top->next->list_data = tmp;
	write(1, "s", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void swap_both_stacks(t_stack *b , t_stack *a)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 2);
}

void push_in_stack(t_stack *from , t_stack *to)
{
	t_list *tmp = from->stack_data->next;
	t_list *last = from->top->prev;
	t_list *current = from->stack_data;
	
	current->next = NULL;
	current->prev = NULL;
	push(to, current);
	
	from->top = tmp;
	from->stack_data = from->top;
	
	from->size--;
	to->size++;
	if(from->size)
	{
		last->next = tmp;
		tmp->prev = last;
	}
	write(1, "p", 1);
	write(1, &to->name, 1);
	write(1, "\n", 1);
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
	write(1, "r", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void rotate_both_stacks(t_stack *a, t_stack *b)
{
    rotate_stack(a);
    rotate_stack(b);
	write(1, "rr\n", 3);
}

void reverse_rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
	write(1, "rr", 2);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
    reverse_rotate_stack(a);
    reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
}