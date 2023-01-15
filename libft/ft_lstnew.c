/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:46:40 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/15 12:51:25 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
// #include <libc.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (0);
	p->content = content;
	p->next = 0;
	return (p);
}


// int main()

// {

// 	int t = 10;

// 	int *d = (int *)malloc(sizeof(int));
// 	d[0] = t;
// 	t_list *node;

// 	node = ft_lstnew(d);
// 	int data = (int)node->content;
// 	printf("%d\n", data);
	
// }