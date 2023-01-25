/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:58:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/24 18:02:03 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <unistd.h>
# include <stdlib.h>

char	*ft_join(char *s1, const char *s2);
int		ft_search(const char *data);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *src);
char	*ft_strdup(const char *string);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);

#endif