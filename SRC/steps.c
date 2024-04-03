/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:02:24 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/05 13:24:57 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_out(t_struct *map)
{
	close_win("The game has closed successfully!\n", map);
	return (0);
}

void	close_win(char *str, t_struct *map)
{
	ft_putstr_fd(str, 1);
	mlx_clear_window(map->ptr->mlx, map->ptr->win);
	mlx_destroy_window(map->ptr->mlx, map->ptr->win);
	exit(0);
}

static void	change_map(t_struct *map, int x, int y)
{
	char		**fmap;
	static int	i;

	fmap = map->fullmap;
	if ((fmap[y][x] == 'E' && map->c_count != 0) || fmap[y][x] == '1')
		return ;
	ft_putnbr_fd(++i, 1);
	write(1, "\n", 1);
	if (map->fullmap[y][x] == 'C')
		map->c_count -= 1;
	if (map->fullmap[y][x] == 'E' && map->c_count == 0)
		close_win("IT'S VALINOR TIME!\n", map);
	map->fullmap[map->point->y][map->point->x] = '0';
	map->fullmap[y][x] = 'P';
	map->point->x = x;
	map->point->y = y;
	put_image(map->ptr->mlx, map->ptr->win, *map, *map->img);
}

int	move_player(int keycd, t_struct *map)
{
	int	x;
	int	y;

	x = map->point->x;
	y = map->point->y;
	if (keycd == 53)
		close_win("The game has closed successfully!\n", map);
	if (keycd == 126 || keycd == 13)
		change_map(map, x, y - 1);
	if (keycd == 125 || keycd == 1)
		change_map(map, x, y + 1);
	if (keycd == 124 || keycd == 2)
		change_map(map, x + 1, y);
	if (keycd == 123 || keycd == 0)
		change_map(map, x - 1, y);
	return (0);
}
