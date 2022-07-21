/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/21 10:41:35 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*enterinline(char **line, char **backup)
{
	*backup = ft_strdup(ft_strchr(*line, '\n') + 1);
	*(ft_strchr(*line, '\n') + 1) = 0;
	return (*line);
}

char	*enterinbuf(char **line, char **backup, char (*buf)[BUFFER_SIZE + 1])
{
	*backup = ft_strdup(ft_strchr(*buf, '\n') + 1);
	*(ft_strchr(buf[0], '\n') + 1) = 0;
	*line = ft_strjoin(*line, buf[0]);
	return (*line);
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
		ft_bzero(buf, BUFFER_SIZE);
		if (ft_strchr(line, '\n'))
			return (enterinline(&line, &backup));
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
		if (r == 0)
			return (line);
		if (ft_strchr(buf, '\n'))
			return (enterinbuf(&line, &backup, &buf));
		line = ft_strjoin(line, buf);
	}
}
