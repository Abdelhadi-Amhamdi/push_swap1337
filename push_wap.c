/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_wap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 09:08:56 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/02 13:18:35 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main()
{
	t_stack a;
	t_stack b;
	int ac = 5;
	// char *av[3] = {"7", "10", "0"};
	char *av[5] = {"0", "-6", "-10", "5", "7"};
	if (!(init_stack(ac, av, &a, &b)))
		return 0;

	if(ac <= 3)
		sort_three_args(&a);
	else if(ac <= 5)
		sort_five_args(&a, &b);
		
		
	

	// printf("----------\n");
	// printf("%d\n", get_the_longest_subscence(a, &b));
	// printf("----------\n");
	// sort_stack_a(&a, &b);
	// push_from_b_and_sort(&a, &b);

	
	// new.next = top
	// top.prev = new
	// new.prev = last
	// last.next = new

    printf("----------\n");
	print_list(a.stack_data);
	printf("----------\n");
	// print_list((b).stack_data);

	// print_list(a.stack_data);
}
