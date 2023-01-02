/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/02 11:58:25 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_args(t_stack *a)
{
	if (a->top->list_data > a->top->next->list_data)
	{
		swap_stack(a);
		printf("sa\n");
	}
	if (a->top->list_data > a->top->prev->list_data)
	{
		reverse_rotate_stack(a);
		printf("rra\n");
	}
	else if (a->top->next->list_data > a->top->prev->list_data)
	{
		reverse_rotate_stack(a);
		printf("rra\n");
		swap_stack(a);
		printf("sa\n");
	}
}

void sort_five_args(t_stack *stack_a, t_stack *stack_b)
{
	t_list *min;
		
	min = get_min(stack_a->top);
	while (1)
	{
		if (stack_a->top->list_data == min->list_data)
		{
			push_in_stack(stack_a, stack_b);
			printf("pb\n");
			min = get_min(stack_a->top);
		}
		else
		{
			if(min->index+1 < (stack_a->size + 1) / 2 )
			{
				reverse_rotate_stack(stack_a);
				printf("rra\n");
			}
			else
			{
				rotate_stack(stack_a);
				printf("ra\n");
			}
		}
		if(stack_b->size == 2)
			break;
	}
	sort_three_args(stack_a);
	push_in_stack(stack_b, stack_a);
	printf("pa\n");
	push_in_stack(stack_b, stack_a);
	printf("pa\n");
}

int get_max_index(int *tab)
{
	int max_value = *tab;
	int index = 0;

	while (tab[index])
	{
		if (tab[index] > max_value)
			max_value = tab[index];
		index++;
	}
	return max_value;
}

int get_the_longest_subscence(t_stack a, t_stack *b)
{
	int increasing[7] = {1, 1, 1, 1, 1, 0};
	int max_index;
	int count_unsorted_nodes = 0;
	t_list *tmp;
	int index = 1;

	tmp = a.stack_data;
	while (tmp->next)
	{
		if (tmp->next->list_data > tmp->list_data)
			increasing[index] = increasing[index - 1] + 1;
		// else
		// 	increasing[index] = increasing[index -1];
		index++;
		tmp = tmp->next;
	}
	printf("----------\n");
	print_tab_int(increasing);
	printf("----------\n");
	max_index = get_max_index(increasing);

	index--;
	while (tmp)
	{
		if (increasing[index] == max_index)
		{
			tmp->is_longest = 1;
			max_index--;
		}
		else
			count_unsorted_nodes++;
		tmp = tmp->prev;
		index--;
	}
	return count_unsorted_nodes;
}

void push_from_b_and_sort(t_stack *a, t_stack *b)
{
	t_list *tmp;

	tmp = b->stack_data;
	while (tmp->next)
	{
		b->stack_data->index++;
		if (b->stack_data->list_data > a->top->list_data)
			b->stack_data->index++;
		tmp = tmp->next;
	}
	tmp = b->top;
	while (tmp)
	{
		push_in_stack(b, a);
		printf("pa\n");
		int last = get_last_node(a->stack_data)->list_data;
		if (a->stack_data->list_data > last)
		{
			rotate_stack(a);
			printf("ra\n");
		}
		else if (a->stack_data->list_data > a->stack_data->next->list_data)
		{
			swap_stack(a);
			printf("sa\n");
		}
		tmp = tmp->next;
	}
}

void sort_stack_a(t_stack *a, t_stack *b)
{
	int first_longest_sub = -1;
	t_list *tmp;
	while (first_longest_sub != (*a).top->list_data)
	{
		if (!(*a).top->is_longest)
		{
			(*a).top->next->prev = NULL;
			push_in_stack(a, b);
			printf("pb\n");
		}
		else
		{
			if (first_longest_sub == -1)
				first_longest_sub = (*a).top->list_data;
			rotate_stack(a);
			printf("ra\n");
		}
	}
}
