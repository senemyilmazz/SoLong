/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:28:31 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/09 13:57:26 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*buffer(char *nextline, int fd)
{
	int		countread;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	countread = 1;
	while (!(gn_strchr(nextline, '\0')) && countread != 0)
	{
		countread = read(fd, buf, BUFFER_SIZE);
		if (countread == -1)
		{
			free(nextline);
			free(buf);
			return (0);
		}
		buf[countread] = '\0';
		nextline = gn_strjoin(nextline, buf);
	}
	free(buf);
	return (nextline);
}

char	*get_next_line(int fd, t_struct *map)
{
	static char	*nextline;

	if (BUFFER_SIZE <= 0 || fd < 0)
		put_error("File does not exist!\n", map);
	nextline = buffer(nextline, fd);
	if (!(nextline))
		put_error("Map could not be read!\n", map);
	if (!(*nextline))
		put_error("Empty map!\n", map);
	return (nextline);
}
