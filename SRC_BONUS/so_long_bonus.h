/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senyilma <senyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:32:23 by senyilma          #+#    #+#             */
/*   Updated: 2023/05/09 14:04:45 by senyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"
# include <stdlib.h>

# define BUFFER_SIZE 42
# define CHARS "01CEPX"
# define WALL "./images/wall.xpm"
# define GROUND "./images/ground.xpm"
# define EXIT "./images/volcano.xpm"
# define COLLECTIBLE1 "./images/ring1.xpm"
# define COLLECTIBLE2 "./images/ring2.xpm"
# define COLLECTIBLE3 "./images/ring3.xpm"
# define COLLECTIBLE4 "./images/ring4.xpm"
# define COLLECTIBLE5 "./images/ring5.xpm"
# define COLLECTIBLE6 "./images/ring6.xpm"
# define COLLECTIBLE7 "./images/ring7.xpm"
# define COLLECTIBLE8 "./images/ring8.xpm"
# define COLLECTIBLE9 "./images/ring9.xpm"
# define COLLECTIBLE10 "./images/ring10.xpm"
# define COLLECTIBLE11 "./images/ring11.xpm"
# define COLLECTIBLE12 "./images/ring12.xpm"
# define PLAYER "./images/frodo.xpm"
# define ENEMY "./images/gollum.xpm"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_image
{
	void	**coin;
	void	*wa;
	void	*p;
	void	*g;
	void	*e;
	void	*en;
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
	t_point	*en_co;
	t_image	*img;
	t_mlx	*ptr;
	t_list	**co_co;
	int		i;
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
void	put_image(void *mlx, void *win, t_struct *map, t_image img);
int		move_player(int keycd, t_struct *map);
void	close_win(char *str, t_struct *map);
int		game_out(t_struct *map);
int		sprite(t_struct *map);
void	free_co_co(t_struct *map);

#endif
