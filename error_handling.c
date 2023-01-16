/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:05:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/16 16:30:11 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*join_all_args(char **av, int ac)
{
	int		index ;
	char	*data ;

	index = 1;
	data = ft_calloc(sizeof(char), 1);
	while (index < ac)
	{
		data = ft_strjoin(data, av[index]);
		index++;
	}
	return (data);
}

size_t	ft_lenght(char **tabs)
{
	size_t	index;

	index = 0 ;
	while (tabs[index])
		index++;
	return (index);
}

int	*filter_args(char **tabs, size_t size)
{
	int	index;
	int	j;
	int	*data;
	int	num;

	index = 0 ;
	data = ft_calloc(size, sizeof(int));
	if (!data)
		return (NULL);
	while (tabs[index])
	{
		j = 0;
		while (tabs[index][j] != '\0')
		{
			if (!ft_isdigit(tabs[index][j]) && tabs[index][j] != '-')
			{
				// free_all(tabs);
				printf("Error\n");
				return (NULL);
			}
			j++;
		}
		num = ft_atoi(tabs[index]);
		if (num >= 2147483647 || num <= -2147483648)
		{
			printf("Error\n");
			return (free(data), NULL);
		}
		data[index] = num;
		if (!check_deplucate(data, num, index))
		{
			printf("Error\n");
			return (free(data), NULL);
		}
		free(tabs[index]);
		index++;
	}
	return (data);
}

int	check_deplucate(int *data, int num, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (data[index] == num)
			return (0);
		index++;
	}
	return (1);
}