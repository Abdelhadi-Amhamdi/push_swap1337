/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:05:51 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 18:59:27 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_lenght(char **tabs)
{
	int	index;

	index = 0 ;
	while (tabs[index])
		index++;
	return (index);
}

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
	char	*data ;
	int		i ;
	int		j;

	i = 0;
	data = NULL;
	while (++i < ac)
	{
		j = 0;
		if ((!*av[i]) || (*av[i] == ' ' && check_empty_arg(av[i])))
			return (NULL);
		while (av[i][j] != '\0')
		{
			if (!check_valid_data(av[i][j], av[i][j +1]))
				return (NULL);
			j++;
		}
		data = ft_strjoin(data, av[i]);
		if (!data)
			return (NULL);
	}
	return (data);
}

int	*filter_args(char **tabs, int size)
{
	int	index;
	int	*data;
	int	num;

	index = 0 ;
	data = ft_calloc(size, sizeof(int));
	if (!data)
		return (ft_free(NULL, tabs), NULL);
	while (tabs[index])
	{
		num = ft_atoi(tabs[index]);
		if ((tabs[index][0] == '-' && num > 0) || \
		(tabs[index][0] != '-' && num < 0) || (ft_strlen(tabs[index]) > 11))
			return (ft_free(data, tabs), NULL);
		data[index] = num;
		if (!check_deplucate(data, num, index))
			return (ft_free(data, tabs), NULL);
		index++;
	}
	ft_free(NULL, tabs);
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
