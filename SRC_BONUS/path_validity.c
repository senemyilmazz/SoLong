/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:01:49 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/05 13:01:27 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static char	**old_map(t_struct *map, char **oldmap, int row)
{
	int	i;

	oldmap = (char **)malloc(sizeof(char *) * (row + 1));
	if (!oldmap)
		put_error("The map could not be preserved!\n", map);
	i = -1;
	while (map->fullmap[++i])
		oldmap[i] = ft_strdup(map->fullmap[i]);
	oldmap[i] = 0;
	return (oldmap);
}

static	void	flood_fill_for_c(t_struct *map, int y, int x)
{
	if (y >= map->size->y || y < 0 || x >= map->size->x || x < 0
		|| map->fullmap[y][x] == '1' || map->fullmap[y][x] == 'E'
		|| map->fullmap[y][x] == 'B')
		return ;
	map->fullmap[y][x] = 'B';
	flood_fill_for_c(map, y, x - 1);
	flood_fill_for_c(map, y, x + 1);
	flood_fill_for_c(map, y - 1, x);
	flood_fill_for_c(map, y + 1, x);
}

static	void	flood_fill_for_e(t_struct *map, int y, int x)
{
	if (y >= map->size->y || y < 0 || x >= map->size->x || x < 0
		|| map->fullmap[y][x] == '1' || map->fullmap[y][x] == 'S'
		|| map->fullmap[y][x] == 'C')
		return ;
	map->fullmap[y][x] = 'S';
	flood_fill_for_e(map, y, x - 1);
	flood_fill_for_e(map, y, x + 1);
	flood_fill_for_e(map, y - 1, x);
	flood_fill_for_e(map, y + 1, x);
}

void	path_validity(t_struct *map)
{
	int		i;
	int		j;
	char	**oldmap;

	oldmap = NULL;
	oldmap = old_map(map, oldmap, map->size->y);
	flood_fill_for_c(map, map->point->y, map->point->x);
	flood_fill_for_e(map, map->point->y, map->point->x);
	i = -1;
	while (map->fullmap[++i])
	{
		j = -1;
		while (map->fullmap[i][++j])
		{
			if (map->fullmap[i][j] && (map->fullmap[i][j] == 'C'
			|| map->fullmap[i][j] == 'P' || map->fullmap[i][j] == 'E'))
				oldmap[0][0] = '0';
		}
		free(map->fullmap[i]);
	}
	free(map->fullmap);
	map->fullmap = oldmap;
}
