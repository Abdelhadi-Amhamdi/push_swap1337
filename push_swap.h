/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:24:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/30 17:12:30 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libc.h"


typedef struct s_list
{
	int list_data;
	struct s_list *next;
	struct s_list *prev;
	int is_longest;
	int index;

} t_list;

typedef struct s_stack
{
	struct s_list *stack_data;
	struct s_list *top;
	int size;

} t_stack;

void	print_tab_int(int *tab);
void get_the_longest_subscence(t_stack a, t_stack *b);
void sort_stack_a(t_stack *a, t_stack *b);
void push_from_b_and_sort(t_stack *a, t_stack *b);

int is_empty(t_stack *stack);

void	push(t_stack *stack, int data);
void	pop(t_stack *stack);

void	swap_both_stacks(t_stack *b , t_stack *a);
void	swap_stack(t_stack *stack);

void	push_in_stack(t_stack *from , t_stack *to);

t_list *creat_node(int  data, int index);
void	print_list(t_list *list);
t_list	*get_last_node(t_list *list);
void	insert_node(t_list **list, t_list *node);
int		init_stack(int argc, char **argv, t_stack *a, t_stack *b);
int fill_stack(int argc, char **argv, t_stack *stack);

void	rotate_stack(t_stack *stack);
void	rotate_both_stacks(t_stack *a, t_stack *b);
void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both_stacks(t_stack *a, t_stack *b);


#endif