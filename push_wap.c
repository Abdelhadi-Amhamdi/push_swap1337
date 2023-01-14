/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:08:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/14 17:09:28 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int main()
{
	t_stack a;
	t_stack b;
	int ac = 7;

	int data[ac];
	int i = 0;
	int j = 1;
	while(i < ac)
	{
		if(contains(av[j], ' '))
		{
			tabs = ft_split(av[i], ' ');
			while(*tabs)
			{
				while(**tabs)
				{
					if(!ft_isdigit(**tabs))
					{
						printf("Error alphabets founded...\n");
						return(0);
					}
					**tabs++;
				}
				data[i] = ft_atoi(*tabs);
				i++;
				tabs++;
			}
		}
		else
		{
			data[i] = ft_atoi(av[j]);
			i++;
		}
		j++;
	}
	char *av[7] = {"4", "8", "3", "100", "33", "55", "10"};
	// ac--;
	// av++;
	if (!(init_stack(ac, av, &a, &b)))
		return 0;
	
	if(ac <= 3)
		sort_three(&a);
	else if(ac <= 5)
		sort_five(&a, &b);
	else
		sort_algo(&a, &b);
		
    printf("----------\n");
	print_list(a.stack_data);
	printf("----------\n");
	print_list(b.stack_data);

}
