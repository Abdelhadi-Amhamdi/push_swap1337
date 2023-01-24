/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/23 15:46:42 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_sorted_numbers(t_list *list, int s)
{
	t_list	*min_node;
	t_list	*tmp;
	t_list	*ptr;

	min_node = list;
	min_node->less_than = (s - 1);
	tmp = list;
	while (1)
	{
		tmp = tmp->next;
		ptr = tmp;
		if (tmp->list_data == min_node->list_data)
			break ;
		while (1)
		{
			ptr = ptr->next;
			if (ptr->list_data > tmp->list_data)
				tmp->less_than++;
			if (ptr->list_data == min_node->list_data)
				break ;
		}
	}
	mark_sorted_numbers(list);
}

void	mark_sorted_numbers(t_list *list)
{
	t_list	*min_node;
	t_list	*tmp;
	int		prev_less;
	int		prev_val;
	t_list	*max_index;

	min_node = list;
	tmp = min_node;
	tmp->is_longest = 1;
	prev_less = tmp->less_than;
	prev_val = tmp->list_data;
	while (1)
	{
		max_index = get_max_index(tmp, list->less_than);
		if (max_index->less_than < prev_less && max_index->list_data > prev_val)
		{
			max_index->is_longest = 1;
			prev_less = max_index->less_than;
			prev_val = max_index->list_data;
		}
		tmp = max_index;
		if (tmp->list_data == min_node->list_data || max_index->less_than == 0)
			break ;
	}
}

void	ft_calc_mouves(t_stack *a, t_stack *b)
{
	t_list	*list_b;
	t_list	*next_node;
	int		a_mouves;
	int		b_mouves;

	list_b = b->stack_data;
	while (list_b)
	{
		b_mouves = list_b->less_than;
		next_node = get_next_min(a->stack_data, list_b);
		if (!next_node)
			a_mouves = ft_search(a->stack_data, 0);
		else
			a_mouves = next_node->less_than;
		list_b->is_longest = ft_calc(a_mouves, b_mouves, a->size, b->size);
		list_b = list_b->next;
		if (list_b->list_data == b->top->list_data)
			break ;
	}
}

void	index_by_sort(t_list *list, int size)
{
	t_list	*first_min;
	int		index;

	first_min = get_next_min(list, NULL);
	index = 0;
	while (1)
	{
		first_min->index = index;
		first_min = get_next_min(list, first_min);
		index++;
		if (index == size)
			break ;
	}
}

t_list	*get_closest_node(t_list *list, int size)
{
	t_list	*closer;
	t_list	*tmp;
	int		top;

	top = list->list_data;
	closer = NULL;
	tmp = list;
	reindex_list(tmp);
	while (1)
	{
		if (tmp->is_longest == 1 && !closer)
			closer = tmp;
		if (tmp->is_longest == 1)
		{
			if ((tmp->less_than >= size / 2) && \
				((size - tmp->less_than) < closer->less_than))
			closer = tmp;
		}
		tmp = tmp->next;
		if (tmp->list_data == top)
			break ;
	}
	return (closer);
}
