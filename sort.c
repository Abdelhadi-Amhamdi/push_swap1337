/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/16 17:36:57 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	if (a->top->list_data > a->top->next->list_data)
		swap_stack(a);
	if (a->top->list_data > a->top->prev->list_data)
		reverse_rotate_stack(a);
	else if (a->top->next->list_data > a->top->prev->list_data)
	{
		reverse_rotate_stack(a);
		swap_stack(a);
	}
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*min;

	min = get_min(stack_a->top);
	while (1)
	{
		if (stack_a->top->list_data == min->list_data)
		{
			push_in_stack(stack_a, stack_b);
			min = get_min(stack_a->top);
		}
		else
		{
			if (min->index + 1 < (stack_a->size + 1) / 2)
				reverse_rotate_stack(stack_a);
			else
				rotate_stack(stack_a);
		}
		if (stack_a->size == 3)
			break ;
	}
	sort_three(stack_a);
	while (stack_b->stack_data)
		push_in_stack(stack_b, stack_a);
}

int	get_max_index(int *tab)
{
	int	max_index;
	int	index;

	max_index = *tab;
	index = 0;
	while (tab[index])
	{
		if (tab[index] > max_index)
			max_index = tab[index];
		index++;
	}
	return (max_index);
}

int	find_sorted_numbers(t_stack *stack_a)
{
	t_list	*min_node;
	t_list	*tmp;
	t_list	*ptr;
	int		size;
	t_list	*max_index;
	int		prev_less;
	int		prev_val;

	min_node = stack_a->top
	min_node->less_than = (stack_a->size - 1);
	size = 0;
	tmp = min_node;
	while (1)
	{
		tmp = tmp->next;
		ptr = tmp;
		if (tmp->list_data == min_node->list_data)
			break ;
		while (1)
		{
			ptr = ptr->next;
			if (ptr->list_data == min_node->list_data)
				break ;
			if (ptr->list_data > tmp->list_data)
				size++;
		}
		tmp->less_than = size;
		size = 0;
	}
	tmp = min_node;
	tmp->is_longest = 1;
	prev_less = tmp->less_than;
	prev_val = tmp->list_data;
	while (1)
	{
		max_index = get_max(tmp, stack_a->top->less_than);
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
	return (1);
}

void	calc_moves(t_stack *a, t_stack *b)
{
	t_list	*next_node;
	t_list	*tmp_b;
	t_list	*tmp_a;
	int		b_moves;
	int		a_moves;
	int		top;

	if (!b->stack_data)
		return ;
	tmp_b = b->stack_data;
	tmp_a = a->stack_data;
	top = tmp_b->list_data;
	while (tmp_b)
	{
		next_node = get_next_min(tmp_a, tmp_b);
		if (!next_node)
			a_moves = 0;
		else
			a_moves = next_node->less_than;
		if (a_moves >= (a->size / 2))
			a_moves = a->size - a_moves;
		b_moves = tmp_b->less_than;
		if (b_moves >= b->size / 2)
			b_moves = b->size - b_moves;
		tmp_b->is_longest = (a_moves + b_moves);
		tmp_b = tmp_b->next;
		if (tmp_b->list_data == top)
			break ;
	}
}

t_list	*get_min_moves(t_list *list)
{
	t_list	*min;
	int		top;

	min = list;
	if (list)
	{
		top = list->list_data;
		while (1)
		{
			list = list->next;
			if (list->list_data == top)
				break ;
			if (list->is_longest < min->is_longest)
				min = list;
		}
	}
	return (min);
}

void	move_min_to_top(t_stack *stack)
{
	int	min_position;

	min_position = ft_search(stack->stack_data, 0);
	while (1)
	{
		if (stack->stack_data->index == 0)
			break ;
		else if (min_position >= (stack->size / 2))
			reverse_rotate_stack(stack);
		else
			rotate_stack(stack);
	}
}

void	move_node_to_top(t_stack *stack, t_list *item)
{
	while (1)
	{
		if (stack->stack_data->list_data == item->list_data)
			break ;
		if (item->less_than >= (stack->size / 2))
			reverse_rotate_stack(stack);
		else
			rotate_stack(stack);
	}
}

t_list	*get_item(t_list *list, int index)
{
	int		top;
	t_list	*tmp;

	tmp = list;
	top = list->list_data;
	while (1)
	{
		if (tmp->index > index)
			return (tmp);
		tmp = tmp->next;
		if (tmp->list_data == top)
			break ;
	}
	return (NULL);
}

void	push_and_sort(t_stack *a, t_stack *b)
{
	t_list	*min_moves;
	t_list	*item;

	while (1)
	{
		calc_moves(a, b);
		min_moves = get_min_moves(b->stack_data);
		move_node_to_top(b, min_moves);
		reindex_list(b->stack_data);
		if (b->stack_data == min_moves)
		{
			item = get_next_min(a->stack_data, min_moves);
			if (!item)
				move_min_to_top(a);
			else
			{
				move_node_to_top(a, item);
				reindex_list(a->stack_data);
			}
			push_in_stack(b, a);
			if (!b->size)
			{
				b->stack_data = NULL;
				b->top = NULL;
				break ;
			}
			reindex_list(a->stack_data);
			reindex_list(b->stack_data);
		}
	}
	move_min_to_top(a);
}

void	clean_stack(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	int		top;
	t_list	*next;

	tmp = a->stack_data;
	top = tmp->list_data;
	while (1)
	{
		next = tmp->next;
		if (!tmp->is_longest)
		{
			move_node_to_top(a, tmp);
			push_in_stack(a, b);
			reindex_list(a->stack_data);
		}
		tmp = next;
		if (tmp->list_data == top)
			break ;
	}
}

void	sort_algo(t_stack *stack_a, t_stack *stack_b)
{
	move_min_to_top(stack_a);
	if (!check_sort(stack_a))
	{
		find_sorted_numbers(stack_a);
		reindex_list(stack_a->stack_data);
		clean_stack(stack_a, stack_b);
		reindex_list(stack_a->stack_data);
		reindex_list(stack_b->stack_data);
		push_and_sort(stack_a, stack_b);
	}
}
