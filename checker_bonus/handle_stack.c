/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:24:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/25 12:50:39 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	init_stack(int len, int *data, t_stack *a_stack, t_stack *b_stack)
{
	b_stack->size = 0;
	a_stack->size = (int)len;
	a_stack->name = 'a';
	b_stack->name = 'b';
	b_stack->stack_data = NULL;
	if (!(fill_stack(len, data, a_stack)))
	{
		free(data);
		return (0);
	}
	return (1);
}

void	free_list(t_list *list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

int	fill_stack(int len, int *data, t_stack *stack)
{
	t_list	*my_list;
	t_list	*node;

	my_list = NULL;
	while (len--)
	{
		if (!my_list)
		{
			my_list = creat_node(data[len]);
			if (!my_list)
				return (0);
		}
		else
		{
			node = creat_node(data[len]);
			if (!node)
				return (free_list(my_list), 0);
			insert_node(&my_list, node);
		}
	}
	stack->stack_data = my_list;
	stack->top = my_list;
	make_list_circular(stack);
	return (1);
}

t_list	*creat_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->list_data = data;
	node->index = 0;
	node->is_longest = 0;
	node->next = NULL;
	node->prev = NULL;
	node->less_than = 0;
	return (node);
}

void	insert_node(t_list **list, t_list *node)
{
	(*list)->prev = node;
	node->next = *list;
	*list = node;
}
