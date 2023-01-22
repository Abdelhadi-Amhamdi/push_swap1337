/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:05:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/22 20:23:33 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	check_empty_arg(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] != ' ')
			return (0);
		index++;
	}
	return (1);
}

char	*join_all_args(char **av, int ac)
{
	int		index ;
	char	*data ;
	int		j;

	index = 1;
	data = ft_calloc(sizeof(char), 1);
	while (index < ac)
	{
		j = 0;
		if (!av[index][0] || av[index][0] == ' ')
		{
			if ((av[index][0] == ' ' && check_empty_arg(av[index])) || \
			!av[index][0])
				return (printf("Error\n"), NULL);
		}
		while (av[index][j] != '\0')
		{
			if ((!ft_isdigit(av[index][j]) && av[index][j] != '-') && \
			(av[index][j] != ' '))
				return (printf("Error\n"), NULL);
			if (av[index][j] == '-' && \
			(!av[index][j + 1] || av[index][j + 1] == ' '))
				return (printf("Error\n"), NULL);
			j++;
		}
		data = ft_strjoin(data, av[index]);
		index++;
	}
	return (data);
}

int	*filter_args(char **tabs, size_t size)
{
	int	index;
	int	*data;
	int	num;
	int	sign;

	index = 0 ;
	data = ft_calloc(size, sizeof(int));
	if (!data)
		return (NULL);
	while (tabs[index])
	{
		num = ft_atoi(tabs[index]);
		sign = check_sign(tabs[index]);
		if ((sign < 0 && num > 0) || (sign > 0 && num < 0) || \
		(ft_strlen(tabs[index]) > 11))
		{
			printf("Error\n");
			free(data);
			return (NULL);
		}
		data[index] = num;
		if (!check_deplucate(data, num, index))
		{
			printf("Error\n");
			free(data);
			return (NULL);
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
