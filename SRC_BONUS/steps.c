/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:02:24 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/09 14:45:27 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_co_co(t_struct *map)
{
	t_list	*iter;
	t_list	*temp;

	iter = *map->co_co;
	while (iter)
	{
		temp = iter;
		iter = iter->next;
		free(temp);
	}	
}

static void	new_player_co(t_struct *map, int x, int y)
{
	map->fullmap[map->point->y][map->point->x] = '0';
	map->fullmap[y][x] = 'P';
	map->point->x = x;
	map->point->y = y;
}

static void	put_step(t_struct *map, int i)
{
	char	*step;

	step = ft_itoa(i);
	mlx_string_put(map->ptr->mlx, map->ptr->win, 5, 30, 0xFF5733, "STEP:");
	mlx_string_put(map->ptr->mlx, map->ptr->win, 45, 30, 0xFF5733, step);
	free(step);
}

static void	change_map(t_struct *map, int x, int y)
{
	char		**fmap;
	static int	i;

	fmap = map->fullmap;
	mlx_clear_window(map->ptr->mlx, map->ptr->win);
	if ((fmap[y][x] == 'E' && map->c_count != 0) || fmap[y][x] == '1')
	{
		put_image(map->ptr->mlx, map->ptr->win, map, *map->img);
		put_step(map, i);
		return ;
	}
	ft_putnbr_fd(++i, 1);
	write(1, "\n", 1);
	if (map->fullmap[y][x] == 'C')
		map->c_count -= 1;
	if (map->fullmap[y][x] == 'X')
		close_win("YOU THIEF!\n", map);
	if (map->fullmap[y][x] == 'E' && map->c_count == 0)
		close_win("IT'S VALINOR TIME!\n", map);
	new_player_co(map, x, y);
	put_image(map->ptr->mlx, map->ptr->win, map, *map->img);
	put_step(map, i);
}

int	move_player(int keycd, t_struct *map)
{
	int	x;
	int	y;

	x = map->point->x;
	y = map->point->y;
	if (keycd == 53)
		close_win("The game has closed successfully!\n", map);
	free_co_co(map);
	*map->co_co = NULL;
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
