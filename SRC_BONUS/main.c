/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:32:05 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/05 16:48:47 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	put_error(char *str, t_struct *map)
{
	int	i;

	i = -1;
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	if (map)
	{
		free(map->point);
		free(map->size);
		free(map->en_co);
		free(map->img);
		free(map->ptr);
		free(map->co_co);
		if (map->fullmap)
		{
			while (map->fullmap[++i])
				free(map->fullmap[i]);
		}
		free(map->fullmap);
	}
	exit(1);
}

void	fill_t_struct(t_struct *map)
{
	map->point = malloc(sizeof(t_point));
	map->size = malloc(sizeof(t_point));
	map->en_co = malloc(sizeof(t_point));
	map->img = malloc(sizeof(t_image));
	map->ptr = malloc(sizeof(t_mlx));
	map->co_co = malloc(sizeof(t_list *));
	*map->co_co = NULL;
	map->fullmap = NULL;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
	map->i = 0;
}

int	main(int argc, char **argv)
{
	t_struct	*map;

	if (argc == 2)
	{
		if ((ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4)) == 0)
			put_error("The map file must be in *.ber format!\n", 0);
		map = malloc(sizeof(t_struct));
		fill_t_struct(map);
		map_validity(argv[1], map);
		create_window(map);
		mlx_hook(map->ptr->win, 02, 1L << 0, move_player, map);
		mlx_hook(map->ptr->win, 17, 1L << 17, game_out, map);
		mlx_loop_hook(map->ptr->mlx, sprite, map);
		mlx_loop(map->ptr->mlx);
		free(map->ptr->mlx);
	}
	else
		put_error("invalid arg", 0);
	return (0);
}
