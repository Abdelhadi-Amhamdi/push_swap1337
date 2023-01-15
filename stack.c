/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:10:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/15 17:29:09 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int init_stack(size_t len, int *data, t_stack *a_stack, t_stack *b_stack)
{
	a_stack->size = 0;
	b_stack->size = 0;
	a_stack->name = 'a';
	b_stack->name = 'b';
	b_stack->stack_data = NULL;
	if (!(fill_stack(len, data, a_stack)))
		return 0;
	index_by_sort(a_stack->stack_data, a_stack->size);
	return 1;
}

int fill_stack(size_t len, int *data, t_stack *stack)
{
	size_t index = 0;
	t_list *my_list;
	t_list *node;
	my_list = NULL;

	stack->size = (int)len;
	len--;

	while (index <= len)
	{
		node = NULL;
		if (!my_list)
		{
			if (!(my_list = creat_node(data[len-index])))
				return (0);
		}
		else
		{
			if (!(node = creat_node(data[len-index])))
			{
				// free_all();
				return (0);
			}
			insert_node(&my_list, node);
		}
		index++;
	}
	stack->stack_data = my_list;
	stack->top = my_list;
	make_list_circular(stack);
	return 1;
}

t_list *creat_node(int data)
{
	t_list *node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	node->list_data = data;
	node->index = 0;
	node->is_longest = 0;
	node->next = NULL;
	node->prev = NULL;
	node->less_than = 0;

	return node;
}

void insert_node(t_list **list, t_list *node)
{
	(*list)->prev = node;
	node->next = *list;
	*list = node;
}