/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:08:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/16 16:07:46 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	*args_data;
	char	**tabs;
	int		*data;
	size_t	size;

	if (ac > 1)
	{
		args_data = join_all_args(av, ac);
		tabs = ft_split(args_data, ' ');
		free(args_data);
		size = ft_lenght(tabs);
		data = filter_args(tabs, size);
		if (data == NULL)
			return (0);
		if (!(init_stack(size, data, &a, &b)))
			return (0);
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