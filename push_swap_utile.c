/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/30 18:10:26 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *creat_node(int data, int index)
{
	t_list *node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return NULL;
	node->list_data = data;
	node->index = index;
	node->is_longest = 0;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void insert_node(t_list **list, t_list *node)
{
	(*list)->prev = node;
	node->next = *list;
	*list = node;
}

int fill_stack(int argc, char **argv, t_stack *stack)
{
	int index = 0;
	t_list *my_list;

	my_list = NULL;

	while (index < argc)
	{
		if (!my_list)
		{
			if (!(my_list = creat_node(atoi(argv[index]), index)))
				return (0);
		}
		else
		{
			t_list *node;
			if (!(node = creat_node(atoi(argv[index]), index)))
			{
				// free_all();
				return (0);
			}
			insert_node(&my_list, node);
		}
		index++;
	}
	stack->stack_data = my_list;
	stack->top = my_list;
	stack->size = argc;
	return 1;
}

void print_list(t_list *list)
{
	t_list *tmp;
	tmp = list;
	while (tmp)
	{
		printf("%d --", tmp->is_longest);
		printf(" %d\n", tmp->list_data);
		tmp = tmp->next;
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

void get_the_longest_subscence(t_stack a, t_stack *b)
{
	int increasing[7] = {1, 1, 1, 1,1, 0};
	int max_index;
	int min_val;
	t_list *tmp;
	int index = 1;

	tmp = a.stack_data;
	while (tmp->next)
	{
		if (tmp->next->list_data > tmp->list_data)
			increasing[index] = increasing[index -1] + 1;
		else
			increasing[index] = increasing[index -1];
		index++;
		tmp = tmp->next;
	}
	
	max_index = get_max_index(increasing);

	index--;
	while (tmp)
	{
		if (increasing[index] == max_index)
		{
			tmp->is_longest = 1;
			max_index--;
		}
		tmp = tmp->prev;
		index--;
	}
	// print_tab_int(increasing);
	sort_stack_a(&a, b);
	push_from_b_and_sort(&a, b);

	// printf("----------\n");
	print_list(a.stack_data);
	// printf("----------\n");
	// print_list((*b).stack_data);
}

void push_from_b_and_sort(t_stack *a, t_stack *b)
{
	t_list *tmp;

	tmp = b->stack_data;
	while(tmp->next)
	{
		b->stack_data->index++;
		if(b->stack_data->list_data > a->top->list_data)
			b->stack_data->index++;
		tmp = tmp->next;
	}
	tmp = b->top;
	while(tmp)
	{
		push_in_stack(b, a);
		printf("pa\n");
		int last = get_last_node(a->stack_data)->list_data;
		if(a->stack_data->list_data > last)
		{
			rotate_stack(a);
			printf("ra\n");
		}
		else if(a->stack_data->list_data > a->stack_data->next->list_data)
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
	while(first_longest_sub != (*a).top->list_data)
	{
		if(!(*a).top->is_longest)
		{
			tmp = (*a).top->next;
			printf("%d\n", tmp->list_data);
			// push_in_stack(a, b);
			printf("pb\n");
			// (*a).top = tmp;
			// (*a).stack_data = tmp;
		}
		else{
			if(first_longest_sub == -1)
				first_longest_sub = (*a).top->list_data;
			rotate_stack((a));
			printf("ra\n");
		}
		printf("----------\n");
		// print_list(a->top);
	}
}

int init_stack(int argc, char **argv, t_stack *a_stack, t_stack *b_stack)
{

	a_stack->size = 0;
	b_stack->size = 0;
	if (!(fill_stack(argc, argv, a_stack)))
		return 0;
	return 1;
}

void print_tab_int(int *tab)
{
	int index = 0;
	while(tab[index])
		printf("%d\n", tab[index++]);
}

int main()
{
	t_stack a;
	t_stack b;
	int ac = 5;
	char *av[5] = {"60", "9", "7", "20", "1"};
	if (!(init_stack(ac, av, &a, &b)))
		return 0;

	get_the_longest_subscence(a, &b);

	// print_list(a.stack_data);
}
