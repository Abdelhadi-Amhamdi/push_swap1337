/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:17:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/25 17:29:26 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calc_exact_mouves(int *a, int *b, int sa, int sb)
{
	if (*a > (sa / 2))
		*a = (sa - *a);
	if (*b > (sb / 2))
		*b = (sb - *b);
}

void	reindex_list(t_list *list)
{
	int	top;
	int	index;

	if (!list)
		return ;
	top = list->list_data;
	index = 0;
	while (list)
	{
		list->less_than = index;
		list = list->next;
		if (list->list_data == top)
			break ;
		index++;
	}
}

int	check_mouves_match(t_list *item1, int m, t_stack *a, t_stack *b)
{
	if ((m && item1->less_than) && \
	((m > (a->size / 2) && item1->less_than > (b->size / 2)) || \
	(m <= (a->size / 2) && item1->less_than <= b->size / 2)))
		return (1);
	return (0);
}

void	reindex_both_stacks(t_stack *a, t_stack *b)
{
	reindex_list(a->stack_data);
	reindex_list(b->stack_data);
}

void	sort_algo(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*min;

	min = get_min(stack_a->stack_data);
	find_sorted_numbers(min, stack_a->size);
	reindex_list(stack_a->stack_data);
	clean_stack_a(stack_a, stack_b);
	reindex_list(stack_a->stack_data);
	reindex_list(stack_b->stack_data);
	ft_push_and_sort(stack_a, stack_b);
	stack_b->stack_data = NULL;
	stack_b->top = NULL;
	reindex_list(stack_a->stack_data);
	move_min_to_top(stack_a);
}
