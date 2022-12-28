/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:21:32 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/26 16:37:24 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_list *creat_node(int  data)
{
	t_list *node;

	if(!(node = malloc(sizeof(t_list))))
		return NULL;
	node->list_data = data;
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

void fill_stack(int argc, char **argv, t_stack *stack)
{
	int index = 0;
	t_list *my_list;
	
	while(index < argc-1)
	{
		if(!my_list)
			my_list = creat_node(atoi(argv[index]));
		else
		{
			t_list *node;
			node = creat_node(atoi(argv[index]));
			insert_node(&my_list, node);
		}
		index++;
	}
	stack->stack_data = my_list;
	stack->top = my_list;
	stack->size = (argc -1);
}

void print_list(t_list *list)
{
	t_list *tmp;
	tmp = list;
	while(tmp)
	{
		printf("%d\n",tmp->list_data);
		tmp = tmp->next;
	}
}
int init_stack(int argc, char **argv, t_stack *a_stack, t_stack *b_stack)
{
	a_stack = NULL;
	b_stack = NULL;
	
	if(!(a_stack = malloc(sizeof(t_stack))))
		write(2, "Error\n", 6);
	a_stack->stack_data = NULL;
	a_stack->top = NULL;
	a_stack->size = 0;
	if(!(b_stack = malloc(sizeof(t_stack))))
	{
		free(a_stack);
		write(2, "Error\n", 6);
	}
	b_stack->stack_data = NULL;
	b_stack->top = NULL;
	b_stack->size = 0;
	fill_stack(argc, argv, a_stack); 
	print_list(a_stack->stack_data);
	return 1;
}

int main()
{
	t_stack *a;
	t_stack *b;
	int ac = 7;
	char *av[7] = {"abc" , "1", "2", "5", "7", "3", "9"};
	init_stack(ac, av+1, a, b);
	// 	print_list(b->stack_data);
}