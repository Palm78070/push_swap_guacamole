/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:23:41 by rthammat          #+#    #+#             */
/*   Updated: 2022/08/01 16:28:15 by rath             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
//char	*ft_strjoin2(char const *s1, char const *s2);
//char	*ft_strchr2(const char *s, int c);
//char	*ft_substr2(char const *s, unsigned int start, size_t len);
//void	*ft_calloc2(size_t count, size_t size);
size_t	ft_strxlen(const char *s, char delim);

#endif
