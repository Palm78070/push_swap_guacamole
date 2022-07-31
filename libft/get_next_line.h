/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:23:41 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/31 20:33:10 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*get_next_line(int fd);
//char	*ft_strjoin(char const *s1, char const *s2);
//char	*ft_strchr(const char *s, int c);
//char	*ft_substr(char const *s, unsigned int start, size_t len);
//void	*ft_calloc(size_t count, size_t size);
size_t	ft_strxlen(const char *s, char delim);

#endif
