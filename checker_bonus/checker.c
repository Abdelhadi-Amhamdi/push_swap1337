/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:41:43 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 15:20:56 by aamhamdi         ###   ########.fr       */
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

int	args_handler(char *line, t_stack *a, t_stack *b, size_t len)
{
	if (!ft_strncmp(line, "sa", len))
		swap_stack(a);
	else if (!ft_strncmp(line, "sb", len))
		swap_stack(b);
	else if (!ft_strncmp(line, "pa", len))
		push_in_stack(b, a);
	else if (!ft_strncmp(line, "pb", len))
		push_in_stack(a, b);
	else if (!ft_strncmp(line, "ra", len))
		rotate_stack(a);
	else if (!ft_strncmp(line, "rb", len))
		rotate_stack(b);
	else if (!ft_strncmp(line, "rr", len))
		rotate_both_stacks(a, b);
	else if (!ft_strncmp(line, "rra", len))
		reverse_rotate_stack(a);
	else if (!ft_strncmp(line, "rrb", len))
		reverse_rotate_stack(b);
	else if (!ft_strncmp(line, "rrr", len))
		reverse_rotate_both_stacks(a, b);
	else
		return (0);
	return (1);
}

void	exec_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!args_handler(line, a, b, ft_strlen(line)))
		{
			free(line);
			return ;
		}
		free(line);
		line = get_next_line(0);
	}
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
		exec_instructions(&a, &b);
		if (check_sort(&a))
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	return (0);
}
