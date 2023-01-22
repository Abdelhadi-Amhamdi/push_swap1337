/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:08:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 00:34:07 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"


void print_list(t_list *list)
{
	int top;
	t_list *tmp;

	if(list)
	{
		top = list->list_data;
		tmp = list;
		while(tmp)
		{
			printf("value: %d -- index: %d -- less: %d -- isl: %d\n", tmp->list_data, tmp->index, tmp->less_than, tmp->is_longest);
			tmp = tmp->next;
			if(tmp->list_data == top)
				break;
		}
	}
	
}

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
		if(!args_data)
			return 0;
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
