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

static double	fix_fisheye(t_inter wall, double angle, double player_angle)
{
	double	angle_fix;

	angle_fix = normalize_angle(angle - player_angle);
	wall.distance *= cos(angle_fix);
	return (wall.distance);
}

int	render_frame(t_map *map, t_player *player, t_mlx *mlx_data)
{
	double	angle;
	t_inter	closest_wall;
	int		i;

	i = 0;
	while (i < PLANE_WIDTH)
	{
		angle = normalize_angle(atan2((i - 0.5) - PLANE_WIDTH / 2.0, \
				player->plane_dist) + player->angle);
		closest_wall = find_closest_wall(angle, player, map);
		closest_wall.distance = fix_fisheye(closest_wall, angle, player->angle);
		trace_column(closest_wall, i, mlx_data, player->plane_dist);
		i++;
	}
	return (0);
}
