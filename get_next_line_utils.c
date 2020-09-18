/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 04:05:06 by jtong             #+#    #+#             */
/*   Updated: 2020/09/18 04:37:25 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end)
		end++;
	return (end - str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strnew(size_t size)
{
	unsigned char	*out;

	size = size + 1;
	if (!(out = (unsigned char *)malloc(size)))
		return (NULL);
	while (size-- > 0)
		((unsigned char *)out)[size] = '\0';
	return ((char *)out);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s || !(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	i = 0;
	while ((str[i] = s[start + i]) && ++i < len)
		;
	if (i < len)
		str[i] = '\0';
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(*str) * (len + ft_strlen(s2) + 1))))
		return (NULL);
	len = 0;
	while (s1[len] != '\0')
	{
		str[len] = s1[len];
		len++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[len] = s2[i];
		i++;
		len++;
	}
	str[len] = s2[i];
	return (str);
}
