/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:41:43 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 21:07:09 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"

int	*parsing(char **av, int ac, size_t *size)
{
	char	*args_data;
	char	**tabs;

	args_data = join_all_args(av, ac);
	if (!args_data)
		return (0);
	tabs = ft_split(args_data, ' ');
	if (!tabs)
		return (0);
	free(args_data);
	*size = ft_lenght(tabs);
	return (filter_args(tabs, *size));
}

int	args_handler(char *line, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(line, "sa", (2 * sizeof(char))))
		swap_stack(a);
	else if (!ft_strncmp(line, "sb", (2 * sizeof(char))))
		swap_stack(b);
	else if (!ft_strncmp(line, "pa", (2 * sizeof(char))))
		push_in_stack(b, a);
	else if (!ft_strncmp(line, "pb", (2 * sizeof(char))))
		push_in_stack(a, b);
	else if (!ft_strncmp(line, "ra", (2 * sizeof(char))))
		rotate_stack(a);
	else if (!ft_strncmp(line, "rb", (2 * sizeof(char))))
		rotate_stack(b);
	else if (!ft_strncmp(line, "rr", (3 * sizeof(char))))
		rotate_both_stacks(a, b);
	else if (!ft_strncmp(line, "rra", (3 * sizeof(char))))
		reverse_rotate_stack(a);
	else if (!ft_strncmp(line, "rrb", (3 * sizeof(char))))
		reverse_rotate_stack(b);
	else if (!ft_strncmp(line, "rrr", (3 * sizeof(char))))
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
		if (!args_handler(line, a, b))
		{
			free(line);
			printf("Error\n");
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	size_t	size;
	int		*data;

	if (ac > 1)
	{
		data = parsing(av, ac, &size);
		if (data == NULL)
			return (0);
		if (!(init_stack(size, data, &a, &b)))
			return (0);
		if (!check_sort(&a))
		{
			exec_instructions(&a, &b);
			if (check_sort(&a))
				printf("OK\n");
			else
				printf("KO\n");
		}
		else
			printf("OK\n");
	}
}
