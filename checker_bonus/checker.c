/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:41:43 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/25 14:38:19 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*parsing(char **av, int ac, int *size)
{
	char	*args_data;
	char	**tabs;

	args_data = join_all_args(av, ac);
	if (!args_data)
		return (0);
	tabs = ft_split(args_data, ' ');
	free(args_data);
	if (!tabs)
		return (0);
	*size = ft_lenght(tabs);
	return (filter_args(tabs, *size));
}

int	args_handler(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa", 2))
		swap_stack(a);
	else if (!ft_strncmp(line, "sb", 2))
		swap_stack(b);
	else if (!ft_strncmp(line, "pa", 2))
		push_in_stack(b, a);
	else if (!ft_strncmp(line, "pb", 2))
		push_in_stack(a, b);
	else if (!ft_strncmp(line, "ra", 2))
		rotate_stack(a);
	else if (!ft_strncmp(line, "rb", 2))
		rotate_stack(b);
	else if (!ft_strncmp(line, "rra", 3))
		reverse_rotate_stack(a);
	else if (!ft_strncmp(line, "rrb", 3))
		reverse_rotate_stack(b);
	else if (!ft_strncmp(line, "rrr", 3))
		reverse_rotate_both_stacks(a, b);
	else if (!ft_strncmp(line, "rr", 2))
		rotate_both_stacks(a, b);
	else
		return (0);
	return (1);
}

int	exec_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!args_handler(line, a, b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		size;
	int		*data;

	if (ac > 1)
	{
		data = parsing(av, ac, &size);
		if (data == NULL)
			return (ft_putendl_fd("Error", 2), 0);
		if (!(init_stack(size, data, &a, &b)))
			return (ft_putendl_fd("Error", 2), 0);
		if (!exec_instructions(&a, &b))
			ft_putendl_fd("Error", 2);
		else if (check_sort(&a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
		make_list_not_circular(&a);
		free_list(a.stack_data);
	}
	exit (0);
}
