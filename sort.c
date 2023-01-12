/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/12 18:54:35 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int where(t_stack *stack, int index);

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
			if (min->index + 1 < (stack_a->size + 1) / 2)
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
		if (stack_a->size == 3)
			break;
	}

	sort_three_args(stack_a);
	while (stack_b->stack_data)
	{
		push_in_stack(stack_b, stack_a);
		printf("pa\n");
	}
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

int get_sorted_numbers(t_stack *stack_a)
{
	t_list *min_node = stack_a->top;
	t_list *tmp;
	t_list *ptr;
	int size = 0;

	min_node->less_than = stack_a->size - 1;

	tmp = min_node;
	while (1)
	{

		tmp = tmp->next;
		if (tmp->list_data == min_node->list_data)
			break;
		ptr = tmp;
		while (1)
		{
			ptr = ptr->next;
			if (ptr->list_data == min_node->list_data)
				break;
			if (ptr->list_data > tmp->list_data)
				size++;
		}
		tmp->less_than = size;
		size = 0;
	}

	tmp = min_node;
	tmp->is_longest = 1;
	t_list *max_index;
	int prev_less;
	prev_less = tmp->less_than;

	while (1)
	{
		max_index = get_max(tmp);
		if (max_index->less_than != prev_less)
			max_index->is_longest = 1;
		prev_less = max_index->less_than;
		tmp = max_index;
		if (tmp->list_data == min_node->list_data || max_index->less_than == 0)
			break;
	}
	return 1;
}

int get_the_longest_subscence(t_stack *a, t_stack *b)
{
	int size = a->size + 1;
	int *increasing;
	int max_index;
	int top_value = a->top->list_data;
	int count_unsorted_nodes = 0;

	increasing = calloc(size, sizeof(int));
	increasing[size] = 0;
	memset(increasing, 1, sizeof(int) * size);

	t_list *tmp;
	int index = 1;

	tmp = a->stack_data;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->list_data == top_value)
			break;
		if (tmp->prev->list_data < tmp->list_data)
			increasing[index] = increasing[index - 1] + 1;
		index++;
	}
	printf("----------\n");
	print_tab_int(increasing);
	printf("----------\n");
	max_index = get_max_index(increasing);

	index--;
	while (tmp)
	{
		tmp = tmp->prev;
		if (tmp->list_data == top_value)
			break;
		if (increasing[index] == max_index)
		{
			tmp->is_longest = 1;
			max_index--;
		}
		else
			count_unsorted_nodes++;
		index--;
	}
	return count_unsorted_nodes;
}

void calc_moves(t_stack *a, t_stack *b)
{
	t_list *tmp_b = b->stack_data;
	int top = tmp_b->list_data;

	t_list *tmp_a = a->stack_data;

	while (tmp_b)
	{
		int a_moves = ft_search(tmp_a, tmp_b->index);

		if (a_moves == -1)
			a_moves = 0;
		int b_moves;

		if (tmp_b->less_than > b->size / 2)
			b_moves = tmp_b->less_than - (b->size / 2);
		else
			b_moves = tmp_b->less_than;
		tmp_b->is_longest = (a_moves + b_moves);
		tmp_b = tmp_b->next;
		if (tmp_b->list_data == top)
			break;
	}
}

t_list *get_min_moves(t_list *list)
{
	t_list *min = list;
	int top = list->list_data;
	while (1)
	{

		list = list->next;
		if (list->list_data == top)
			break;
		if (list->is_longest < min->is_longest)
			min = list;
	}
	return min;
}

void make_min_top(t_stack *stack)
{
	int m = ft_search(stack->stack_data, -1);
	while(1)
	{
		if(stack->stack_data->index == 0)
			break;
		else
		{
			reverse_rotate_stack(stack);
			printf("rra\n");
		}
	}
}


void make_it_to_top(t_stack *stack, t_list *item)
{
	while(1)
	{
		if(stack->stack_data->list_data == item->list_data)
			break;
		if(item->less_than > (stack->size / 2))
		{
			reverse_rotate_stack(stack);
			printf("rrb\n");
		}
		else{
			rotate_stack(stack);
			printf("rb\n");
		}
	}
}

t_list  *get_item(t_list *list , int index)
{
	int top = list->list_data;
	t_list *tmp;

	tmp = list;
	while(1)
	{
		if(tmp->index > index)
			return tmp;
		tmp = tmp->next;
		if(tmp->list_data == top)
			break;
	}
	return NULL;
}

void push_from_b_and_sort(t_stack *a, t_stack *b)
{
	t_list *min_moves;
	t_list *item;
		// calc_moves(a, b);

	while(1)
	{
		calc_moves(a, b);
		if(!b->size)
		{
			b->stack_data = NULL;
			b->top = NULL;
			break;
		}
		min_moves = get_min_moves(b->stack_data);
		make_it_to_top(b , min_moves);
		if(b->stack_data == min_moves)
		{
			item = get_item(a->stack_data, min_moves->index);
			if(!item)
				make_min_top(a);
			else
				make_it_to_top(a, item);
			
			push_in_stack(b, a);
			printf("pa\n");
			reindex_stack_a(a->stack_data);
			reindex_stack_a(b->stack_data);
		}
	}
	make_min_top(a);
}

void sort_stack_a(t_stack *a, t_stack *b)
{
	t_list *tmp = NULL;

	while (1)
	{
		if (tmp == NULL && a->top->is_longest == 1)
			tmp = a->top;
		if (a->top->is_longest == 0)
		{
			push_in_stack(a, b);
			printf("pb\n");
		}
		else
		{
			rotate_stack(a);
			printf("ra\n");
		}
		if (a->top == tmp)
			break;
	}
}

void longest_increasing_subsquence_algo(t_stack *stack_a, t_stack *stack_b)
{
	get_sorted_numbers(stack_a);
	sort_stack_a(stack_a, stack_b);
	reindex_stack_a(stack_a->stack_data);
	reindex_stack_a(stack_b->stack_data);
	push_from_b_and_sort(stack_a, stack_b);

	// get_the_longest_subscence(stack_a, stack_b);
}
