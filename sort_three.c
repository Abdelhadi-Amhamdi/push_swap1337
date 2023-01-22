/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:55:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 15:56:10 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *a)
{
	if (a->top->list_data > a->top->next->list_data)
		swap_stack(a);
	if (a->top->list_data > a->top->prev->list_data)
		reverse_rotate_stack(a);
	else if (a->top->next->list_data > a->top->prev->list_data)
	{
		reverse_rotate_stack(a);
		swap_stack(a);
	}
}