/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:43:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 00:43:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"
#include "render.h"
#include <math.h>

static int	fix_fisheye(double wall_dist, double angle, double player_angle)
{
	double	angle_fix;

	angle_fix = player_angle - angle;
	angle_fix = normalize_angle(angle_fix);
	return ((int)ceil(wall_dist * cos(angle_fix)));
}

int	render_frame(t_map *map, t_player *player, t_mlx *mlx_data)
{
	double	angle;
	double	angle_inc;
	double	closest_wall;
	int		i;

	i = 0;
	angle_inc = player->fov / PLANE_WIDTH;
	angle = normalize_angle(player->angle - (player->fov / 2));
	while (i < PLANE_WIDTH)
	{
		closest_wall = find_closest_wall(find_v_wall(angle, player, map), \
						find_h_wall(angle, player, map), player->pos);
		closest_wall = fix_fisheye(closest_wall, angle, player->angle);
		trace_column(closest_wall, i, mlx_data);
		i++;
		angle = normalize_angle(angle + angle_inc);
	}
	return (0);
}
