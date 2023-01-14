/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:10:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/14 13:45:48 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int init_stack(int argc, char **argv, t_stack *a_stack, t_stack *b_stack)
{
	a_stack->size = 0;
	b_stack->size = 0;
	a_stack->name = 'a';
	b_stack->name = 'b';
	b_stack->stack_data = NULL;
	if (!(fill_stack(argc, argv, a_stack)))
		return 0;
	index_by_sort(a_stack->stack_data, a_stack->size);
	move_min_to_top(a_stack);
	return 1;
}

int fill_stack(int argc, char **argv, t_stack *stack)
{
	int index = 0;
	t_list *my_list;
	t_list *node;
	my_list = NULL;

	while (index < argc)
	{
		node = NULL;
		if (!my_list)
		{
			if (!(my_list = creat_node(atoi(argv[index]), index)))
				return (0);
		}
		else
		{
			if (!(node = creat_node(atoi(argv[index]), index)))
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
	make_it_circular(stack);
	stack->size = argc;
	return 1;
}

t_list *creat_node(int data, int index)
{
	t_list *node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	node->list_data = data;
	node->index = index;
	node->is_longest = 0;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void insert_node(t_list **list, t_list *node)
{
	(*list)->prev = node;
	node->next = *list;
	*list = node;
}