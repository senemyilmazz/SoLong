/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:31 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/04 15:26:31 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(void *data)
{
	(void)data;
	return (0);
}

static void	fill_t_image(t_image *img, void *mlx)
{
	img->w = 64;
	img->h = 64;
	img->x = 0;
	img->y = 0;
	img->wa = mlx_xpm_file_to_image(mlx, WALL, &img->w, &img->h);
	img->g = mlx_xpm_file_to_image(mlx, GROUND, &img->w, &img->h);
	img->e = mlx_xpm_file_to_image(mlx, EXIT, &img->w, &img->h);
	img->c = mlx_xpm_file_to_image(mlx, COLLECTIBLE, &img->w, &img->h);
	img->p = mlx_xpm_file_to_image(mlx, PLAYER, &img->w, &img->h);
}

void	put_image(void *mlx, void *win, t_struct map, t_image img)
{
	int		i;
	int		j;

	mlx_clear_window(mlx, win);
	i = -1;
	while (map.fullmap[++i])
	{
		j = -1;
		while (map.fullmap[i][++j])
		{
			if (map.fullmap[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img.wa, img.x, img.y);
			else
				mlx_put_image_to_window(mlx, win, img.g, img.x, img.y);
			if (map.fullmap[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img.p, img.x, img.y);
			if (map.fullmap[i][j] == 'C')
				mlx_put_image_to_window(mlx, win, img.c, img.x, img.y);
			if (map.fullmap[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img.e, img.x, img.y);
			img.x += 64;
		}
		img.x = 0;
		img.y += 64;
	}
}

void	create_window(t_struct *map)
{
	map->ptr->mlx = mlx_init();
	if (map->ptr->mlx == NULL)
		return ;
	map->ptr->win = mlx_new_window(map->ptr->mlx, (map->size->x * 64), \
		(map->size->y * 64), "so_long");
	if (map->ptr->win == NULL)
	{
		free(map->ptr->win);
		return ;
	}
	fill_t_image(map->img, map->ptr->mlx);
	put_image(map->ptr->mlx, map->ptr->win, *map, *map->img);
}
