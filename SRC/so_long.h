/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:32:23 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/05 16:45:28 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define BUFFER_SIZE 42
# define CHARS "01CEP"
# define WALL "./images/wall.xpm"
# define GROUND "./images/ground.xpm"
# define EXIT "./images/volcano.xpm"
# define COLLECTIBLE "./images/ring.xpm"
# define PLAYER "./images/frodo1.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_image
{
	void	*wa;
	void	*p;
	void	*c;
	void	*g;
	void	*e;
	int		w;
	int		h;
	int		x;
	int		y;
}			t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_struct
{
	t_point	*point;
	t_point	*size;
	t_image	*img;
	t_mlx	*ptr;
	char	**fullmap;
	int		c_count;
	int		p_count;
	int		e_count;
}			t_struct;

void	put_error(char *str, t_struct *map);
void	fill_t_struct(t_struct *map);
void	map_validity(char *argv, t_struct *map);
char	*get_next_line(int fd, t_struct *map);
void	path_validity(t_struct *map);
void	create_window(t_struct *map);
void	put_image(void *mlx, void *win, t_struct map, t_image img);
int		move_player(int keycd, t_struct *map);
int		game_out(t_struct *map);
void	close_win(char *str, t_struct *map);

#endif