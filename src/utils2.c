/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:50:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/23 13:17:54 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if ((list->list_data > first_min->list_data) && \
			(list->list_data < min->list_data))
			min = list;
		list = list->next;
		if (list->list_data == top)
			break ;
	}
	return (min);
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

t_list	*get_max_index(t_list *list, int top)
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

t_list	*get_last_node(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
