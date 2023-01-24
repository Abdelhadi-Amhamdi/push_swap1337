/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:11:35 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 15:16:54 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->next;
	stack->stack_data = stack->top;
	ft_putchar_fd('r', 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
}

void	rotate_both_stacks(t_stack *a, t_stack *b)
{
	a->top = a->stack_data->next;
	a->stack_data = a->top;
	b->top = b->stack_data->next;
	b->stack_data = b->top;
	ft_putendl_fd("rr", 1);
}

void	reverse_rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(stack->name, 1);
	ft_putchar_fd('\n', 1);
}

void	reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
	a->top = a->stack_data->prev;
	a->stack_data = a->top;
	b->top = b->stack_data->prev;
	b->stack_data = b->top;
	ft_putendl_fd("rrr", 1);
}

void	make_list_not_circular(t_stack *a)
{
	if (!a->stack_data)
		return ;
	a->top->prev->next = NULL;
	a->top->prev = NULL;
}
