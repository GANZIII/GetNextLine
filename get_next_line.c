/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/18 14:46:11 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 7

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	unsigned long   len;
	unsigned long   i;

	len = 0;
	while (src[len])
		len++;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

unsigned long   ft_strcat(char *dest, const char *src)
{
	unsigned long	len_dest;
	unsigned long	len_src;
	unsigned long	i;

	len_dest = 0;
	len_src = 0;
	while (dest[len_dest])
		len_dest++;
	while (src[len_src])
		len_src++;
	i = 0;
    while (src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (len_dest + len_src);
}

char	*end(int s, char *b, char *big)
{
	char	*little;

	*(b + s) = 0;
	little = ft_strdup(b);
	ft_strcat(big, little);
	//(little);
	return ((char *)big);
}

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
        	if ((++size) + 2 == BUFFER_SIZE)
        	{
            	big = end(size, buf, big);
            	size = 0;
        	}
    	}
	}
}

int main(void)
{
	int fd = open("./hello.txt", O_RDONLY);

	while (1)
	{
		char *line = get_next_line(1);
		printf("%s", line);
	}



	close(fd);
    return (0);
}
