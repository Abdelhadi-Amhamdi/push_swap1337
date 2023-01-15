/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:24:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/15 17:46:25 by aamhamdi         ###   ########.fr       */
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
int get_max_index(int *tab);
t_list *get_min_moves(t_list *list);
int ft_search(t_list *list, int index);
t_list *get_item(t_list *list, int index);
void reindex_list(t_list *list);
void make_list_circular(t_stack *a);
void make_list_not_circular(t_stack *a);
t_list *get_max(t_list *list);
t_list *get_min(t_list *list);
t_list *get_last_node(t_list *list);
t_list *get_next_min(t_list *list, t_list *fmin);
void print_list(t_list *list);


// sorting
void move_min_to_top(t_stack *stack);
void move_node_to_top(t_stack *stack, t_list *item);
void sort_five(t_stack *stack_a, t_stack *stack_b);
void sort_three(t_stack *a);
void sort_algo(t_stack *stack_a, t_stack *stack_b);
int find_sorted_numbers(t_stack *stack_a);
void calc_moves(t_stack *a, t_stack *b);
void push_and_sort(t_stack *a, t_stack *b);
void clean_stack(t_stack *a, t_stack *b);
int check_sort(t_stack *stack);


// stack
t_list *creat_node(int data);
void insert_node(t_list **list, t_list *node);
int init_stack(size_t len, int *data, t_stack *a, t_stack *b);
int fill_stack(size_t len, int *data, t_stack *stack);
int contains(char *str, char c);

// instructions
void push_in_stack(t_stack *from, t_stack *to);
void swap_stack(t_stack *stack);
void swap_both_stacks(t_stack *b, t_stack *a);
void rotate_stack(t_stack *stack);
void rotate_both_stacks(t_stack *a, t_stack *b);
void reverse_rotate_stack(t_stack *stack);
void reverse_rotate_both_stacks(t_stack *a, t_stack *b);


// parsing
int *filter_args(char **av, size_t size);
size_t ft_lenght(char **tabs);
char *join_all_args(char **av, int ac);
int check_deplucate(int *data, int num, int len);

#endif