/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:11:35 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 21:12:24 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->next;
	stack->stack_data = stack->top;
	write(1, "r", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	rotate_both_stacks(t_stack *a, t_stack *b)
{
	a->top = a->stack_data->next;
	a->stack_data = a->top;
	b->top = b->stack_data->next;
	b->stack_data = b->top;
	write(1, "rr\n", 3);
}

void	reverse_rotate_stack(t_stack *stack)
{
	stack->top = stack->stack_data->prev;
	stack->stack_data = stack->top;
	write(1, "rr", 2);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	reverse_rotate_both_stacks(t_stack *a, t_stack *b)
{
	a->top = a->stack_data->prev;
	a->stack_data = a->top;
	b->top = b->stack_data->prev;
	b->stack_data = b->top;
	write(1, "rrr\n", 4);
}
