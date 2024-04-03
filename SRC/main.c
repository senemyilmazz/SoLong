/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:32:05 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/05 16:47:06 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		free(map->img);
		free(map->ptr);
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
	map->img = malloc(sizeof(t_image));
	map->ptr = malloc(sizeof(t_mlx));
	map->fullmap = NULL;
	map->c_count = 0;
	map->e_count = 0;
	map->p_count = 0;
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
		mlx_key_hook(map->ptr->win, move_player, map);
		mlx_hook(map->ptr->win, 17, 1L << 17, game_out, map);
		mlx_loop(map->ptr->mlx);
		free(map->ptr->mlx);
	}
	else
		put_error("invalid arg", 0);
	return (0);
}
