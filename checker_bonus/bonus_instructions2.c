/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:27:22 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/25 12:05:01 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_both_stacks(t_stack *a, t_stack *b)
{
	if (!a->stack_data || !b->stack_data)
		return ;
	rotate_stack(a);
	rotate_stack(b);
}

void	reverse_rotate_stack(t_stack *stack)
{
	if (!stack->stack_data)
		return ;
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
}

void	reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
	if (!a->stack_data || !b->stack_data)
		return ;
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
}

int	ft_is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	check_valid_data(char c, char n)
{
	if (!ft_isdigit(c) && !ft_is_white_space(c) && c != '-' && c != '+')
		return (0);
	if ((c == '-' || c == '+') && (n == '-' || n == '+' || \
	ft_is_white_space(n) || !n))
		return (0);
	if (ft_isdigit(c) && (n == '-' || n == '+'))
		return (0);
	return (1);
}
