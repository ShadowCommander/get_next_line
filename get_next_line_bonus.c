/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:35:10 by jtong             #+#    #+#             */
/*   Updated: 2020/09/18 13:47:12 by jtong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#define FD_MAX 65535

int		get_next_line(const int fd, char **line)
{
	static char	*sav[FD_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		size;

	if (fd < 0 || !line)
		return (-1);
	if (!sav[fd])
		sav[fd] = ft_strnew(0);
	size = 0;
	while (!(tmp = ft_strchr(sav[fd], '\n')) &&
			(size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		tmp = ft_strjoin(sav[fd], buf);
		free(sav[fd]);
		sav[fd] = tmp;
	}
	if (size < 0)
		return (-1);
	*line = ft_strsub(sav[fd], 0, tmp ? tmp - sav[fd] : ft_strlen(sav[fd]));
	tmp = tmp ? ft_strsub(tmp + 1, 0, ft_strlen(tmp + 1)) : NULL;
	free(sav[fd]);
	sav[fd] = tmp;
	return (sav[fd] || **line);
}
