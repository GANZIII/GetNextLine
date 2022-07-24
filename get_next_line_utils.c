/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jijoo <jijoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:45:58 by jijoo             #+#    #+#             */
/*   Updated: 2022/07/24 22:43:32 by jijoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*res;
	long unsigned int	idx;

	if (start >= ft_strlen(s))
	{
		res = (char *)malloc(1);
		if (res == 0)
			return (0);
		*res = 0;
		return (res);
	}
	if (len <= ft_strlen(s))
		res = (char *)malloc(len + 1);
	else
		res = (char *)malloc(ft_strlen(s) + 1);
	if (res == 0)
		return (0);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		res[idx] = s[start + idx];
		idx++;
	}
	res[idx] = 0;
	return (res);
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