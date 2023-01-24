/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:38 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 14:43:43 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	ft_free(void *data, char **tabs)
{
	int	index;

	index = 0;
	if (data)
	{
		free(data);
		data = NULL;
	}
	while (tabs[index])
	{
		free(tabs[index]);
		tabs[index] = NULL;
		index++;
	}
	free(tabs);
	tabs = NULL;
}
