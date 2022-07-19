/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/18 16:11:35 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    	buf[BUFFER_SIZE];
    int     	size;
    static char	*big;
	int			k;

    size = 0;
    big = ft_strdup("");
	while (1)
	{
		k = read(fd, buf + size, 1);
		if (k == -1)
			return (0);
		else if (k == 0)
			return (end(size, buf, big));
   		else if (k == 1)
    	{
			if (*(buf + size) == '\n')
				return (end(size + 1, buf, big));
        	if ((++size) == BUFFER_SIZE)
        	{
            	big = end(size, buf, big);
            	size = 0;
        	}
    	}
	}
}