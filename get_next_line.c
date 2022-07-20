/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/20 21:09:42 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 999999
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;
	char	*new;

	new = (char *)s;
	idx = 0;
	while (idx < n)
	{
		*(new + idx) = '\0';
		idx++;
	}
}

char    *get_next_line(int fd)
{
	char static	*backup;
   	char		buf[BUFFER_SIZE + 1];
	int			r;
	char		*line;

	buf[BUFFER_SIZE] = 0;
	line = ft_strdup("");
	if (backup)
		line = ft_strjoin("", backup);
	while (1)
	{
		if (r == -1)
			return (0);
		ft_bzero(buf, BUFFER_SIZE);
		if (ft_strchr(line, '\n'))
		{
			backup = ft_strdup(ft_strchr(line, '\n') + 1);
			*(ft_strchr(line, '\n') + 1) = 0;
			return (line);
		}
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0)
		{
			*backup = 0;
			return (line);
		}
		if (ft_strchr(buf, '\n'))
		{
			backup = ft_strdup(ft_strchr(buf, '\n') + 1);
			*(ft_strchr(buf, '\n') + 1) = 0;	
			line = ft_strjoin(line, buf);
			return (line);
		}
		line = ft_strjoin(line, buf);
	}
}

int	main(void)
{
	int fd = open("./hello.txt", O_RDONLY);
	for (int i = 0; i < 11; i++)
	{
		char	*str = get_next_line(fd);
		printf("(%d) str : %s",i,  str);
	}
	close(fd);
	return (0);
}