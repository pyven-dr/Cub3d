/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:46:56 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 00:46:56 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "point.h"
# include "player.h"
# include "game_loop.h"

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
	double		texture_x;
	double		texture_y;
}			t_inter;

t_point	find_v_wall(double ray_angle, t_player *player, t_map_data *map);
t_point	find_h_wall(double ray_angle, t_player *player, t_map_data *map);
t_inter	find_closest_wall(double angle, t_player *player, t_map_data *map);
void	trace_column(t_inter inter, int col_numb, t_game_data *game_data);
void	find_orientation_ver(t_inter *inter, double ray_angle);
void	find_orientation_hor(t_inter *inter, double ray_angle);
t_inter	find_clos_inter(t_inter ver, t_inter hor, t_map_data *map, \
						double angle);
char	get_map_point(double x, double y, t_map_data *map);

#endif
