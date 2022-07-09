/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:51:45 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/09 21:56:23 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#define BUFFER_SIZE 3

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
char    *get_next_line(int fd)
{
    char    *line;
    char    buf[BUFFER_SIZE];
    int     size;
    char    *little;
    char    *big;

    size = 0;
    big = ft_strdup("");
    while ((read(fd, buf + size, 1) == 1) && (*(buf + size) != '\n'))
    {
        size++;
        if (size + 2 == BUFFER_SIZE)
        {
            *(buf + size) = 0;
            little = ft_strdup(buf);
            ft_strcat(big, little);
            size = 0;
        }
    }
    *(buf + size) = 0;
    little = ft_strdup(buf);
    ft_strcat(big, little);
    ft_strcat(big, "\n");
    line = big;
    return (line);
}

int main(void)
{
    int   fp;
    fp = open("./hello.txt", O_RDONLY);
    char    *ret1 = get_next_line(fp);
    printf("ret : %s", ret1);
    char    *ret2 = get_next_line(fp);
    printf("ret : %s", ret2);
    char    *ret3 = get_next_line(fp);
    printf("ret : %s", ret3);
    char    *ret4 = get_next_line(fp);
    printf("ret : %s", ret4);
    close(fp);
    return (0);
}