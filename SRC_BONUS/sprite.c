/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:39:16 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/05 12:00:31 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	animation(t_struct *map)
{
	t_list	*iter;

	iter = *map->co_co;
	while (iter != 0)
	{
		mlx_put_image_to_window(map->ptr->mlx, map->ptr->win, \
		map->img->g, iter->x * 64, iter->y * 64);
		mlx_put_image_to_window(map->ptr->mlx, map->ptr->win, \
		map->img->coin[map->i], (iter->x * 64) + 12, (iter->y * 64) + 12);
		iter = iter->next;
	}
	map->i += 1;
	if (map->i == 10)
		map->i = 0;
	return ;
}

void	new_enemy_co(t_struct *map, int x, int y, int a)
{
		map->fullmap[y][x] = '0';
		map->fullmap[y][a] = 'X';
		map->en_co->x = a;
}

static void	enemy_move(t_struct *map)
{
	static int	flag;
	int			x;
	int			y;

	x = map->en_co->x;
	y = map->en_co->y;
	if (flag == 1 && (map->fullmap[y][x - 1] == '1'
		|| map->fullmap[y][x - 1] == 'E' || map->fullmap[y][x - 1] == 'C'))
		flag = 0;
	if (flag == 0 && (map->fullmap[y][x + 1] != '1'
		&& map->fullmap[y][x + 1] != 'E' && map->fullmap[y][x + 1] != 'C'))
		new_enemy_co(map, x, y, x + 1);
	if (flag == 0 && (map->fullmap[y][x + 1] == '1'
		|| map->fullmap[y][x + 1] == 'E' || map->fullmap[y][x + 1] == 'C'))
		flag = 1;
	if (flag == 1 && (map->fullmap[y][x - 1] != '1'
		&& map->fullmap[y][x - 1] != 'E' && map->fullmap[y][x - 1] != 'C'))
		new_enemy_co(map, x, y, x - 1);
	if (map->point->x == map->en_co->x && map->point->y == map->en_co->y)
		close_win("YOU THIEF!\n", map);
}

int	sprite(t_struct *map)
{
	static int	i;

	i++;
	if (i % 1000 == 0 && map->c_count != 0)
		animation(map);
	if (i % 4000 == 0)
	{
		if (map->en_co->x)
		{
			mlx_put_image_to_window(map->ptr->mlx, map->ptr->win, \
			map->img->g, map->en_co->x * 64, map->en_co->y * 64);
			enemy_move(map);
			mlx_put_image_to_window(map->ptr->mlx, map->ptr->win, \
			map->img->en, (map->en_co->x * 64) + 10, (map->en_co->y * 64) + 14);
		}
	}
	return (0);
}
