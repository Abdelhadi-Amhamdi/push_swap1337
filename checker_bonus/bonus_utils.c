/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:10:27 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 15:23:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_sort(t_stack *stack)
{
	t_list	*tmp;
	int		top;

	tmp = stack->stack_data;
	top = tmp->list_data;
	while (tmp)
	{
		if ((tmp->list_data > tmp->next->list_data) && \
		(tmp->next->list_data != to)p)
			return (0);
		tmp = tmp->next;
		if (tmp->list_data == top)
			break ;
	}
	return (1);
}

t_list	*get_last_node(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_free(void *data, char **tabs)
{
	int	index;

	index = 0;
	if (data)
	{
		free(data);
		data = NULL;
	}
	while (tabs[index])
	{
		free(tabs[index]);
		tabs[index] = NULL;
		index++;
	}
	free(tabs);
	tabs = NULL;
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

void	make_list_not_circular(t_stack *a)
{
	if (!a->stack_data)
		return ;
	a->top->prev->next = NULL;
	a->top->prev = NULL;
}
