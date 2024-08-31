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

#include <math.h>
#include "const_values.h"
#include "render.h"

static double	fix_fisheye(t_inter wall, double angle, double player_angle)
{
	double	angle_fix;

	angle_fix = normalize_angle(angle - player_angle);
	wall.distance *= cos(angle_fix);
	return (wall.distance);
}

int	render_frame(t_game_data *game_data)
{
	double	angle;
	t_inter	closest_wall;
	int		i;

	i = 0;
	while (i < PLANE_WIDTH)
	{
		angle = normalize_angle(atan2((i - 0.5) - PLANE_WIDTH / 2.0, \
				game_data->p.plane_dist) + game_data->p.angle);
		closest_wall = find_closest_wall(angle, &game_data->p, \
									&game_data->map_data);
		closest_wall.distance = fix_fisheye(closest_wall, angle, \
								game_data->p.angle);
		trace_column(&closest_wall, i, game_data);
		i++;
	}
	return (0);
}
