/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:24:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/14 13:47:56 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libc.h"
#include <assert.h>

typedef struct s_list
{
	int list_data;
	struct s_list *next;
	struct s_list *prev;
	int is_longest;
	int less_than;
	int index;

} t_list;

typedef struct s_stack
{
	char name;
	struct s_list *stack_data;
	struct s_list *top;
	int size;

} t_stack;


// utils
void index_by_sort(t_list *list, int size);


// sorting
void move_min_to_top(t_stack *stack);
void sort_five(t_stack *stack_a, t_stack *stack_b);
void sort_three(t_stack *a);


// stack

// instructions
int ft_search(t_list *list, int index);
void print_tab_int(int *tab);
int get_sorted_numbers(t_stack *stack_a);
t_list *get_max(t_list *list);
void check_list(t_stack *stack);
void sort_algo(t_stack *stack_a, t_stack *stack_b);
void sort_stack_a(t_stack *a, t_stack *b);
void push_from_b_and_sort(t_stack *a, t_stack *b);


t_list *get_next_min(t_list *list, t_list *fmin);
void reindex_stack_a(t_list *list);

void push(t_stack *stack, t_list *data);
void pop(t_stack *stack);
void make_it_circular(t_stack *a);
void make_it_not_circular(t_stack *a);
t_list *get_min(t_list *list);

void swap_both_stacks(t_stack *b, t_stack *a);
void swap_stack(t_stack *stack);

void push_in_stack(t_stack *from, t_stack *to);

t_list *creat_node(int data, int index);
void print_list(t_list *list);
t_list *get_last_node(t_list *list);
void insert_node(t_list **list, t_list *node);
int init_stack(int argc, char **argv, t_stack *a, t_stack *b);
int fill_stack(int argc, char **argv, t_stack *stack);

void rotate_stack(t_stack *stack);
void rotate_both_stacks(t_stack *a, t_stack *b);
void reverse_rotate_stack(t_stack *stack);
void reverse_rotate_both_stacks(t_stack *a, t_stack *b);

#endif