/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:43:02 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/09 13:58:53 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	rectangular(t_struct *map)
{
	int	row;
	int	i;
	int	j;
	int	column;

	if (!map->fullmap)
		put_error("Empty file!\n", map);
	row = 0;
	column = 0;
	while (map->fullmap[row])
		row++;
	i = 0;
	while (map->fullmap[i][column])
		column++;
	while (++i < row)
	{
		j = 0;
		while (map->fullmap[i][j])
			j++;
		if (j != column)
			put_error("The map must be rectangular!\n", map);
	}
	map->size->x = column;
	map->size->y = row;
}

static void	wall_around(t_struct *map)
{
	int	row;
	int	i;
	int	j;

	row = 0;
	i = -1;
	while (map->fullmap[row])
		row++;
	while (map->fullmap[0][++i] && map->fullmap[row -1][i])
	{
		if (map->fullmap[0][i] != '1' || map->fullmap[row -1][i] != '1')
			put_error("The map must be surrounded by walls!\n", map);
	}
	j = 0;
	while (++j < row -1)
	{
		if (map->fullmap[j][0] != '1' || map->fullmap[j][i - 1] != '1')
			put_error("The map must be surrounded by walls!\n", map);
	}
}

static void	components(t_struct *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->fullmap[++i])
	{
		j = -1;
		while (map->fullmap[i][++j])
		{
			if (ft_strchr(CHARS, map->fullmap[i][j]) != 1)
				put_error("The map containes invalid character!\n", map);
			if (map->fullmap[i][j] == 'P')
			{
				map->p_count += 1;
				map->point->x = j;
				map->point->y = i;
			}
			if (map->fullmap[i][j] == 'C')
				map->c_count += 1;
			if (map->fullmap[i][j] == 'E')
				map->e_count += 1;
		}
	}
	if (map->e_count != 1 || map->p_count != 1 || map->c_count < 1)
		put_error("The map must containe one P/E and least one C.\n", map);
}

void	map_validity(char *argv, t_struct *map)
{
	char	*fmap;
	int		fd;
	int		i;

	i = -1;
	fmap = NULL;
	fd = open(argv, O_RDONLY);
	fmap = get_next_line(fd, map);
	while (fmap[++i])
	{
		if (fmap[0] == '\n' || (fmap[i] == '\n' && fmap[i + 1] == '\n'))
			put_error("Map must not containe an empty line!\n", map);
	}
	map->fullmap = ft_split(fmap, '\n');
	free(fmap);
	components(map);
	rectangular(map);
	wall_around(map);
	path_validity(map);
	if (map->fullmap[0][0] == '0')
		put_error("Tha path is invalid!\n", map);
}
