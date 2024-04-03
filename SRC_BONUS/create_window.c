/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:57:31 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/09 14:45:10 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill_t_image(t_image *img, void *mlx)
{
	img->coin = (void **)ft_calloc(sizeof(void *), 12);
	img->w = 64;
	img->h = 64;
	img->x = 0;
	img->y = 0;
	img->wa = mlx_xpm_file_to_image(mlx, WALL, &img->w, &img->h);
	img->g = mlx_xpm_file_to_image(mlx, GROUND, &img->w, &img->h);
	img->p = mlx_xpm_file_to_image(mlx, PLAYER, &img->w, &img->h);
	img->e = mlx_xpm_file_to_image(mlx, EXIT, &img->w, &img->h);
	img->en = mlx_xpm_file_to_image(mlx, ENEMY, &img->w, &img->h);
	img->coin[0] = mlx_xpm_file_to_image(mlx, COLLECTIBLE1, &img->w, &img->h);
	img->coin[1] = mlx_xpm_file_to_image(mlx, COLLECTIBLE2, &img->w, &img->h);
	img->coin[2] = mlx_xpm_file_to_image(mlx, COLLECTIBLE3, &img->w, &img->h);
	img->coin[3] = mlx_xpm_file_to_image(mlx, COLLECTIBLE4, &img->w, &img->h);
	img->coin[4] = mlx_xpm_file_to_image(mlx, COLLECTIBLE5, &img->w, &img->h);
	img->coin[5] = mlx_xpm_file_to_image(mlx, COLLECTIBLE6, &img->w, &img->h);
	img->coin[6] = mlx_xpm_file_to_image(mlx, COLLECTIBLE7, &img->w, &img->h);
	img->coin[7] = mlx_xpm_file_to_image(mlx, COLLECTIBLE8, &img->w, &img->h);
	img->coin[8] = mlx_xpm_file_to_image(mlx, COLLECTIBLE9, &img->w, &img->h);
	img->coin[9] = mlx_xpm_file_to_image(mlx, COLLECTIBLE10, &img->w, &img->h);
	img->coin[10] = mlx_xpm_file_to_image(mlx, COLLECTIBLE11, &img->w, &img->h);
	img->coin[11] = mlx_xpm_file_to_image(mlx, COLLECTIBLE12, &img->w, &img->h);
}

static void	collectible_coordinates(t_struct *map, int x, int y)
{
	t_list	*iter;

	ft_lstadd_back(map->co_co, ft_lstnew(x, y));
	iter = *map->co_co;
	if (ft_lstsize(iter) == map->c_count)
	{
		while (iter != 0)
		{
			mlx_put_image_to_window(map->ptr->mlx, map->ptr->win, \
			map->img->coin[map->i], (iter->x * 64) + 12, (iter->y * 64) + 12);
			iter = iter->next;
		}
	}
}

static void	enemy_coordinates(t_struct *map, int x, int y)
{
	map->en_co->x = x;
	map->en_co->y = y;
	mlx_put_image_to_window(map->ptr->mlx, map->ptr->win, \
		map->img->en, (map->en_co->x * 64) + 10, (map->en_co->y * 64) + 14);
}

void	put_image(void *mlx, void *win, t_struct *map, t_image img)
{
	int	i;
	int	j;

	i = -1;
	while (map->fullmap[++i])
	{
		j = -1;
		while (map->fullmap[i][++j])
		{
			mlx_put_image_to_window(mlx, win, img.g, img.x, img.y);
			if (map->fullmap[i][j] == '1')
				mlx_put_image_to_window(mlx, win, img.wa, img.x, img.y);
			if (map->fullmap[i][j] == 'P')
				mlx_put_image_to_window(mlx, win, img.p, img.x + 7, img.y);
			if (map->fullmap[i][j] == 'C')
				collectible_coordinates(map, img.x / 64, img.y / 64);
			if (map->fullmap[i][j] == 'E')
				mlx_put_image_to_window(mlx, win, img.e, img.x, img.y);
			if (map->fullmap[i][j] == 'X')
				enemy_coordinates(map, img.x / 64, img.y / 64);
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
	put_image(map->ptr->mlx, map->ptr->win, map, *map->img);
	mlx_string_put(map->ptr->mlx, map->ptr->win, 5, 30, 0xFF5733, "STEP:");
	mlx_string_put(map->ptr->mlx, map->ptr->win, 45, 30, 0xFF5733, "0");
}
