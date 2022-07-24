/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/24 15:33:37 by jijoo            ###   ########.fr       */
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
	if (ft_strlen(*backup))
	{
		//ft_bzero(*backup, ft_strlen(*backup));
		//sfree(*backup);
	}
	//ft_bzero(*backup, ft_strlen(*backup));
	//free(*backup);
	//if (*backup)
		//free(*backup);
	*backup = ft_strdup(ft_strchr(*line, '\n') + 1);
	*(ft_strchr(*line, '\n') + 1) = 0;
	return (*line);
}

char	*enterinbuf(char **line, char (*buf)[BUFFER_SIZE + 1])
{
	char	*ret;

	*(ft_strchr(buf[0], '\n') + 1) = 0;
	ret = ft_strjoin(*line, buf[0]);
	free(*line);
	return (ret);
}

char	*ft_free(char **li, char **backup)
{
	char	*line;

	line = ft_strjoin(*li, *backup);
	// free backup?
	// free(*backup);
	free(*li);
	ft_bzero(*backup, ft_strlen(*backup));
	free(*backup);
	return (line);
}

char    *get_next_line(int fd)
{
	static char *backup;
   	char		buf[BUFFER_SIZE + 1];
	int			r;
	char		*line;
	char		*temp;

	line = ft_strdup("");
	if (backup)
		line = ft_free(&line, &backup);	
	while (1)	
	{
		ft_bzero(buf, BUFFER_SIZE + 1);
		if (ft_strchr(line, '\n'))
		{
			return (enterinline(&line, &backup));
		}
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
		{
			temp = (ex(r, &line));
			free(line);
			//if (backup)
				//free(backup);
			return (temp);
		}
		if (ft_strchr(buf, '\n'))
		{
			backup = ft_strdup(ft_strchr(buf, '\n') + 1);
			return (enterinbuf(&line, &buf));
		}
		temp = line;
		line = ft_strjoin(line, buf);
		free(temp);
	}
}
