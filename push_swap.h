/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:24:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/12/26 16:13:59 by aamhamdi         ###   ########.fr       */
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

} t_list;

typedef struct s_stack
{
	struct s_list *stack_data;
	struct s_list *top;
	int size;

} t_stack;

int is_empty(t_stack *stack);

void	push(t_stack *stack, int data);
void	pop(t_stack *stack);

void	swap_both_stacks(t_stack *b , t_stack *a);
void	swap_stack(t_stack *stack);

void	push_in_stack(t_stack *from , t_stack *to);

t_list	*creat_node(int  data);
void	print_list(t_list *list);
t_list	*get_last_node(t_list *list);
void	insert_node(t_list **list, t_list *node);
int		init_stack(int argc, char **argv, t_stack *a, t_stack *b);
void	fill_stack(int argc, char **argv, t_stack *stack);

void	rotate_stack(t_stack *stack);
void	rotate_both_stacks(t_stack *a, t_stack *b);

void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both_stacks(t_stack *a, t_stack *b);


#endif