/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:42 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 15:15:48 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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

// instructions
void	swap_stack(t_stack *stack);
void	swap_both_stacks(t_stack *b, t_stack *a);
void	push_in_stack(t_stack *from, t_stack *to);
void	rotate_stack(t_stack *stack);
void	rotate_both_stacks(t_stack *a, t_stack *b);
void	reverse_rotate_stack(t_stack *stack);
void	reverse_rotate_both_stacks(t_stack *a, t_stack *b);

// parsing
int		*parsing(char **av, int ac, int *size);
int		args_handler(char *line, t_stack *a, t_stack *b, size_t len);
void	exec_instructions(t_stack *a, t_stack *b);
int		*filter_args(char **tabs, int size);
char	*join_all_args(char **av, int ac);
void	ft_free(void *data, char **tabs);
int		check_empty_arg(char *str);
int		check_deplucate(int *data, int num, int len);

// utils
t_list	*get_last_node(t_list *list);
int		ft_lenght(char **tabs);
void	make_list_not_circular(t_stack *a);
void	make_list_circular(t_stack *a);
int		check_sort(t_stack *stack);
void	free_list(t_list *list);

// stack
int		init_stack(int len, int *data, t_stack *a_stack, t_stack *b_stack);
int		fill_stack(int len, int *data, t_stack *stack);
t_list	*creat_node(int data);
void	insert_node(t_list **list, t_list *node);

#endif