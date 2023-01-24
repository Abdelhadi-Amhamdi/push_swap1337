/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:08:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 14:41:28 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

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

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		*data;
	int		size;

	if (ac > 1)
	{
		data = parsing(av, ac, &size);
		if (!data)
			return (ft_putendl_fd("Error", 2), 0);
		if (!(init_stack(size, data, &a, &b)))
			return (ft_putendl_fd("Error", 2), 0);
		if (!check_sort(&a))
		{
			if (size <= 3)
				sort_three(&a);
			else if (size <= 5)
				sort_five(&a, &b);
			else
				sort_algo(&a, &b);
		}
	}
	return (0);
}
