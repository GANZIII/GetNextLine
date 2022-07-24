/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/24 23:43:47 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(int fd, char *backup)
{
	int		r;
	char	*toad;
	char	buf[BUFFER_SIZE + 1];

	while (1)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			return (0);
		}
		else if (r == 0)
		{
			break;
		}
		buf[r] = 0;
		if (!backup)
			backup = ft_strdup("");
		toad = backup;
		backup = ft_strjoin(toad, buf);
		free(toad);
		if (ft_strchr(backup, '\n'))
			break;
	}
	return (backup);
}

char	*ft_bu(char *line)
{
	char	*bu;
	int		start;

	start = 0;
	while (line[start] != '\n')
	{
		if (line[start] == 0)
			return (0);
		start++;
	}
	bu = ft_substr(line, start + 1, ft_strlen(line) - start);
	if (!bu)
		return (0);
	if (ft_strlen(bu) == 0)
	{
		free(bu);
		return (0);
	}
	return (bu);
}

char    *get_next_line(int fd)
{
	static char *backup;
	char		*line;
	
	line = ft_line(fd, backup);
	if (!line)
	{
		return (0);
	}
	backup = ft_bu(line);
	if (ft_strchr(line, '\n'))
		*(ft_strchr(line, '\n') + 1) = 0;
	return (line);
}
