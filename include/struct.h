/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:16:06 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/22 16:09:07 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
	int		width;
	int		height;
}			t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img_data;
}			t_mlx;

typedef struct s_keys
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	esc;
}		t_keys;

typedef struct s_point
{
	double	x;
	double	y;
}		t_point;

typedef enum e_orient
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_orient;

typedef struct s_inter
{
	t_point		point;
	double		distance;
	t_orient	orientation;
}			t_inter;

typedef struct s_player
{
	t_keys	keys;
	t_point	pos;
	double	delta_x;
	double	delta_y;
	double	angle;
	double	fov;
	int		plane_dist;
}			t_player;

typedef struct s_color
{
	int     hexa;
    int     r;
    int     g;
    int     b;
}			t_color;

typedef struct s_map_data
{
	char	**map;
    t_data  north;
    t_data  south;
    t_data  east;
    t_data  west;
    t_color	floor;
    t_color	ceiling;
	int     map_height;
    int     map_width;
    int     number_player;
}	t_map_data;

typedef struct s_game_data
{
	t_player	player;
	t_mlx		mlx_data;
	t_map_data	map_data;
}				t_game_data;

#endif