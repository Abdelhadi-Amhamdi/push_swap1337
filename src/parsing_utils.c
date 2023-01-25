/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:36:38 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 19:29:12 by aamhamdi         ###   ########.fr       */
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

int	ft_is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	check_valid_data(char c, char n)
{
	if (!ft_isdigit(c) && !ft_is_white_space(c) && c != '-' && c != '+')
		return (0);
	if ((c == '-' || c == '+') && (n == '-' || n == '+' || \
	ft_is_white_space(n) || !n))
		return (0);
	if (ft_isdigit(c) && (n == '-' || n == '+'))
		return (0);
	return (1);
}
