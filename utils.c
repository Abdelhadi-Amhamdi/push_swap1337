/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:34:37 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/23 15:49:20 by aamhamdi         ###   ########.fr       */
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

int	ft_calc(int a, int b, int sa, int sb)
{
	if ((b > (sb / 2) && a > (sa / 2)) || (b <= (sb / 2) && a <= (sa / 2)))
	{
		calc_exact_mouves(&a, &b, sa, sb);
		return (max(a, b));
	}
	else
	{
		calc_exact_mouves(&a, &b, sa, sb);
		return (a + b);
	}
	return (-1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
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
