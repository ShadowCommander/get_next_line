/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:35:10 by jtong             #+#    #+#             */
/*   Updated: 2020/10/08 21:14:11 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

char	*ft_strreplace(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	return (s2);
}

int		get_next_line(const int fd, char **line)
{
	static char	*sav[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		size;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	size = 0;
	if (!sav[fd])
		sav[fd] = ft_strnew(0);
	while (!(tmp = ft_strchr(sav[fd], '\n')) &&
			(size = read(fd, buf, BUFFER_SIZE)) > 0)
		sav[fd] = ft_strreplace(sav[fd], ft_strnjoin(sav[fd], buf, size));
	if (size < 0)
	{
		free(sav[fd]);
		return (-1);
	}
	*line = ft_strsub(sav[fd], 0,
		tmp ? (size_t)(tmp - sav[fd]) : ft_strlen(sav[fd]));
	if (tmp != NULL)
		tmp++;
	sav[fd] = ft_strreplace(sav[fd], ft_strsub(tmp, 0, ft_strlen(tmp)));
	return (sav[fd] != NULL);
}
