/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:26:01 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 00:52:44 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "map.h"
# include "point.h"

typedef struct s_mouse
{
	int	x;
	int	y;
	int	is_recentering;
}		t_mouse;

typedef struct s_keys
{
	int		forward;
	int		backward;
	int		look_left;
	int		look_right;
	int		right;
	int		left;
	int		up;
	int		down;
	int		fly;
	int		crouch;
	int		esc;
	int		alt;
	int		menu;
	int		hood;
	int		map;
	int		object;
	int		object_sec;
	int		door;
	t_mouse	mouse;
}			t_keys;

typedef struct s_player
{
	t_keys	keys;
	t_point	pos;
	double	delta_x;
	double	delta_y;
	double	angle;
	double	vert_offset;
	double	player_size;
	double	fov;
	int		plane_dist;
}			t_player;

int		key_press(int key, t_keys *keys);
int		key_release(int key, t_keys *keys);
void	move_player(t_player *player, t_map_data *map);
void	rotate_player(t_player *player);
void	player_size(t_player *player);
int		mouse_press(int key, int x, int y, t_keys *keys);
int		mouse_release(int key, int x, int y, t_keys *keys);
int		mouse_leave(t_keys *keys);

#endif
