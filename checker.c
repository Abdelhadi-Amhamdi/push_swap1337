/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:41:43 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/21 21:22:33 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "gnl/get_next_line.h"

int main(int ac, char **av)
{

    t_stack	a;
	t_stack	b;
	char	*args_data;
	char	**tabs;
	int		*data;
	size_t	size;
	int i  = 0;
	char *line;

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
			line = get_next_line(0);
			while(line)
			{
				if(!ft_strncmp(line, "sa", (2 * sizeof(char))))
					swap_stack(&a);
				else if(!ft_strncmp(line , "sb", (2 * sizeof(char))))
					swap_stack(&b);
				else if(!ft_strncmp(line , "pa", (2 * sizeof(char))))
					push_in_stack(&b, &a);
				else if(!ft_strncmp(line , "pb", (2 * sizeof(char))))
					push_in_stack(&a, &b);
				else if(!ft_strncmp(line , "ra", (2 * sizeof(char))))
					rotate_stack(&a);
				else if(!ft_strncmp(line , "rb", (2 * sizeof(char))))
					rotate_stack(&b);
				else if(!ft_strncmp(line , "rr", (3 * sizeof(char))))
					rotate_both_stacks(&a, &b);
				else if(!ft_strncmp(line , "rra", (3 * sizeof(char))))
					reverse_rotate_stack(&a);
				else if(!ft_strncmp(line , "rrb", (3 * sizeof(char))))
					reverse_rotate_stack(&b);
				else if(!ft_strncmp(line , "rrr", (3 * sizeof(char))))
					reverse_rotate_both_stacks(&a, &b);
				line = get_next_line(0);
			}
			
			if(check_sort(&a))
				printf("OK\n");
			else
				printf("KO\n");
		}	
        else{
            printf("OK\n");
        }
	}
    
}