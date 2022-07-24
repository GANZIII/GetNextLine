/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:45:58 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/24 14:37:00 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ex(int r, char **line)
{
	if (r < 0)
	{
		free(*line);
		return (0);
	}
	else
	{
		if (ft_strlen(*line) == 0)
		{
			//free(*line);
			return (0);
		}
		return (*line);
	}
}

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
	//free((char *)src);
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*res;
	int		idx;
	int		j;

	j = 0;
	len = 1 + ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len);
	if (res == 0)
		return (0);
	idx = 0;
	while (s1[idx])
	{
		res[idx] = s1[idx];
		idx++;
	}
	while (s2[j])
	{
		res[idx] = s2[j];
		j++;
		idx++;
	}
	res[idx] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*new;

	new = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (new + i);
		i++;
	}
	if (c == 0)
		return (new + i);
	return (0);
}