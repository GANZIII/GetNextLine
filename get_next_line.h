/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:49:17 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/24 14:55:45 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#define BUFFER_SIZE 2

char    *get_next_line(int fd);
unsigned long	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	ft_bzero(void *s, size_t n);
char	*enterinline(char **line, char **backup);
char	*enterinbuf(char **line, char (*buf)[BUFFER_SIZE + 1]);
char	*ex(int r, char **line);
char	*ft_free(char **li, char **backup);

#endif