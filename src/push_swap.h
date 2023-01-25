/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:24:19 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/25 14:36:53 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				list_data;
	struct s_list	*next;
	struct s_list	*prev;
	int				is_longest;
	int				less_than;
	int				index;
}	t_list;

typedef struct s_stack
{
	char			name;
	struct s_list	*stack_data;
	struct s_list	*top;
	int				size;
}	t_stack;

// utils
void	index_by_sort(t_list *list, int size);
t_list	*get_min_moves(t_list *list);
int		ft_search(t_list *list, int index);
int		ft_calc(int a, int b, int sa, int sb);
int		max(int a, int b);
void	reindex_list(t_list *list);
void	make_list_circular(t_stack *a);
void	make_list_not_circular(t_stack *a);
t_list	*get_max_index(t_list *list, int top);
t_list	*get_next_min(t_list *list, t_list *fmin);
t_list	*get_min(t_list *list);
t_list	*get_closest_node(t_list *list, int size);
void	free_list(t_list *list);

// // sorting
void	move_min_to_top(t_stack *stack);
void	move_node_to_top(t_stack *stack, t_list *item);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *a);
void	sort_algo(t_stack *stack_a, t_stack *stack_b);
void	find_sorted_numbers(t_list *list, int s);
void	clean_stack_a(t_stack *a, t_stack *b);
int		check_sort(t_stack *stack);
void	mark_sorted_numbers(t_list *list);
void	ft_push_and_sort(t_stack *a, t_stack *b);
void	reindex_both_stacks(t_stack *a, t_stack *b);
void	calc_exact_mouves(int *a, int *b, int sa, int sb);
void	ft_calc_mouves(t_stack *a, t_stack *b);
int		check_mouves_match(t_list *item1, int m, t_stack *a, t_stack *b);

// // stack
t_list	*get_last_node(t_list *list);
t_list	*creat_node(int data);
void	insert_node(t_list **list, t_list *node);
int		init_stack(int len, int *data, t_stack *a, t_stack *b);
int		fill_stack(int len, int *data, t_stack *stack);

// // instructions
void	push_in_stack(t_stack *from, t_stack *to);
void	swap_stack(t_stack *stack);
void	swap_both_stacks(t_stack *b, t_stack *a);
void	rotate_stack(t_stack *stack);
void	rotate_both_stacks(t_stack *a, t_stack *b);
void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both_stacks(t_stack *a, t_stack *b);

// // parsing
int		*filter_args(char **av, int size);
int		ft_lenght(char **tabs);
char	*join_all_args(char **av, int ac);
int		check_deplucate(int *data, int num, int len);
void	ft_free(void *data, char **tabs);
int		check_valid_data(char c, char n);

#endif