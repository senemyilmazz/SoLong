/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:28:31 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/09 14:03:47 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	*buffer(char *all_line, int fd)
{
	int		countread;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	countread = 1;
	while (!(gn_strchr(all_line, '\0')) && countread != 0)
	{
		countread = read(fd, buf, BUFFER_SIZE);
		if (countread == -1)
		{
			free(all_line);
			free(buf);
			return (0);
		}
		buf[countread] = '\0';
		all_line = gn_strjoin(all_line, buf);
	}
	free(buf);
	return (all_line);
}

char	*get_next_line(int fd, t_struct *map)
{
	static char	*all_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		put_error("File does not exist!\n", map);
	all_line = buffer(all_line, fd);
	if (!(all_line))
		put_error("Map could not be read!\n", map);
	if (!(*all_line))
		put_error("Empty map!\n", map);
	return (all_line);
}
