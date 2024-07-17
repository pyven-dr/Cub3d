/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:16:06 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 22:16:06 by pyven-dr         ###   ########.fr       */
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
}			t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	*img_data;
}			t_mlx;

typedef struct s_pressed_key
{
	int	forward;
	int	backward;
	int	left;
	int	right;
}		t_pressed_key;

typedef struct s_point
{
	double	x;
	double	y;
	int		map_point;
}		t_point;

typedef struct s_player
{
	t_point	pos;
	double	angle;
	double	fov;
}			t_player;

typedef struct s_map
{
	int	*map;
	int	map_height;
	int	map_width;
}		t_map;

#endif