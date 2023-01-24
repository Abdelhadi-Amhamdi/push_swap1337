/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:28 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 13:23:16 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	swap_stack(t_stack *stack)
{
	int	tmp;

	if (!stack->top)
		return ;
	tmp = stack->top->list_data;
	stack->top->list_data = stack->stack_data->next->list_data;
	stack->top->next->list_data = tmp;
	ft_putchar_fd('s', 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
}

void	swap_both_stacks(t_stack *b, t_stack *a)
{
	swap_stack(a);
	swap_stack(b);
	ft_putendl_fd("ss", 1);
}

void	push(t_stack *from, t_stack *to)
{
	t_list	*tmp;
	t_list	*item;

	item = from->stack_data;
	tmp = item->next;
	item->next = NULL;
	item->prev = NULL;
	if (to->size)
	{
		item->next = to->stack_data;
		to->stack_data->prev = item;
	}
	to->stack_data = item;
	to->top = item;
	if (tmp)
		tmp->prev = NULL;
	from->stack_data = tmp;
	from->top = tmp;
}

void	push_in_stack(t_stack *from, t_stack *to)
{
	make_list_not_circular(to);
	make_list_not_circular(from);
	push(from, to);
	to->size++;
	from->size--;
	if (to->size == 0)
		to->stack_data = NULL;
	if (from->size == 0)
		from->stack_data = NULL;
	make_list_circular(to);
	make_list_circular(from);
	ft_putchar_fd('p', 1);
	ft_putchar_fd(to->name, 1);
	ft_putchar_fd('\n', 1);
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
