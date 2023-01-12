/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:08:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/12 18:56:10 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack a;
	t_stack b;
	int ac = 8;
	// char *av[3] = {"7", "10", "0"};
	char *av[8] = {"9", "8", "10", "7", "70", "3", "100", "0"};
	// ac--;
	// av++;
	if (!(init_stack(ac, av, &a, &b)))
		return 0;
	index_it(a.stack_data, a.size);
	if(ac <= 3)
		sort_three_args(&a);
	else if(ac <= 5)
		sort_five_args(&a, &b);
	else
		longest_increasing_subsquence_algo(&a, &b);
		
    printf("----------\n");
	print_list(a.stack_data);
	printf("----------\n");
	print_list(b.stack_data);

}
