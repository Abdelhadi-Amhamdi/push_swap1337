/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:34:37 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/16 17:22:40 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	t_list	*tmp;
	int		top;

	tmp = stack->stack_data;
	top = tmp->list_data;
	while (tmp)
	{
		tmp = tmp->next;
		if (tmp->list_data == top)
			break ;
		if (tmp->index - 1 != tmp->prev->index)
			return (0);
	}
	return (1);
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

t_list	*get_next_min(t_list *list, t_list *first_min)
{
	t_list	*min;
	int		top;

	top = list->list_data;
	min = NULL;
	if (!first_min)
		return (get_min(list));
	while (list)
	{
		if (!min && list->list_data > first_min->list_data)
			min = list;
		if (list->list_data > first_min->list_data && list->list_data < min->list_data)
			min = list;
		list = list->next;
		if (list->list_data == top)
			break ;
	}
	return (min);
}

void	make_list_circular(t_stack *a)
{
	t_list	*last;

	if (!a->stack_data)
		return ;
	last = get_last_node(a->stack_data);
	last->next = a->top;
	a->top->prev = last;
}

t_list	*get_min(t_list *list)
{
	t_list	*min;

	min = list;
	while (list)
	{
		list = list->next;
		if (list == min)
			break ;
		if (list->list_data < min->list_data)
			min = list;
	}
	return (min);
}

int	ft_search(t_list *list, int index)
{
	t_list	*tmp;
	int		top;

	tmp = list;
	top = tmp->list_data;
	while (1)
	{
		if (tmp->index == index)
			return (tmp->less_than);
		tmp = tmp->next;
		if (tmp->list_data == top)
			break ;
	}
	return (-1);
}

t_list	*get_max(t_list *list, int top)
{
	t_list	*tmp;
	t_list	*max;
	int		max_index;
	int		prev_value;

	max_index = list->less_than;
	prev_value = list->list_data;
	max = list->next;
	tmp = max->next;
	while (1)
	{
		if (tmp->less_than == top)
			break ;
		if (tmp->less_than > max->less_than && tmp->list_data > prev_value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	make_list_not_circular(t_stack *a)
{
	if (!a->stack_data)
		return ;
	a->top->prev->next = NULL;
	a->top->prev = NULL;
}

t_list	*get_last_node(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
