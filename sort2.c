/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:19:24 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 21:22:12 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_min_to_top(t_stack *stack)
{
	int	min_position;

	min_position = ft_search(stack->stack_data, 0);
	while (1)
	{
		if (stack->stack_data->index == 0)
			break ;
		else if (min_position > (stack->size / 2))
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
		if (item->less_than > (stack->size / 2))
			reverse_rotate_stack(stack);
		else
			rotate_stack(stack);
	}
}

void	ft_push_and_sort(t_stack *a, t_stack *b)
{
	t_list	*min_mouves;
	t_list	*item;
	int		m;

	while (1)
	{
		ft_clac_mouves(a, b);
		min_mouves = get_min_moves(b->stack_data);
		item = get_next_min(a->stack_data, min_mouves);
		if (!item)
			m = ft_search(a->stack_data, 0);
		else
			m = item->less_than;
		if (((m && min_mouves->less_than) && ((m > (a->size / 2) && \
			min_mouves->less_than > (b->size / 2)) || \
			(m <= (a->size / 2) && min_mouves->less_than <= b->size / 2))))
		{
			while (1)
			{
				if ((min_mouves->index == b->top->index) || \
					(m == a->top->less_than))
					break ;
				if (min_mouves->less_than > (b->size / 2))
					reverse_rotate_both_stacks(a, b);
				else
					rotate_both_stacks(a, b);
			}
		}
		move_node_to_top(b, min_mouves);
		if (!item)
			move_min_to_top(a);
		else
			move_node_to_top(a, item);
		push_in_stack(b, a);
		if (!b->size)
		{
			b->stack_data = NULL;
			b->top = NULL;
			reindex_list(a->stack_data);
			break ;
		}
		reindex_list(a->stack_data);
		reindex_list(b->stack_data);
	}
	move_min_to_top(a);
}

void	clean_stack_a(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	t_list	*top;
	t_list	*next;

	top = get_closest_node(a->stack_data, a->size);
	tmp = top;
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
		if (tmp->index == top->index)
			break ;
	}
}

void	sort_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*min;

	min = get_min(stack_a->stack_data);
	if (!check_sort(stack_a))
	{
		find_sorted_numbers(min, stack_a->size);
		reindex_list(stack_a->stack_data);
		clean_stack_a(stack_a, stack_b);
		reindex_list(stack_a->stack_data);
		reindex_list(stack_b->stack_data);
		ft_push_and_sort(stack_a, stack_b);
	}
}
