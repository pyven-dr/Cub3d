/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:44:56 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 00:44:56 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "render.h"
#include <math.h>

void	find_orientation_ver(t_inter *inter, double ray_angle)
{
	if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
		inter->orientation = WEST;
	else if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
		inter->orientation = EAST;
}

void	find_orientation_hor(t_inter *inter, double ray_angle)
{
	if (ray_angle > M_PI)
		inter->orientation = NORTH;
	else if (ray_angle < M_PI)
		inter->orientation = SOUTH;
}

t_inter	find_distance(t_point ver, t_point hor, t_point *p_pos, double angle)
{
	t_inter	dist_ver;
	t_inter	dist_hor;

	dist_ver.distance = sqrt((ver.x - p_pos->x) * (ver.x - p_pos->x) + \
					(ver.y - p_pos->y) * (ver.y - p_pos->y));
	dist_hor.distance = sqrt((hor.x - p_pos->x) * (hor.x - p_pos->x) + \
					(hor.y - p_pos->y) * (hor.y - p_pos->y));
	if (dist_ver.distance < 0)
		dist_ver.distance = HEIGHT;
	if (dist_hor.distance < 0)
		dist_hor.distance = HEIGHT;
	if (dist_ver.distance < dist_hor.distance)
	{
		find_orientation_ver(&dist_ver, angle);
		return (dist_ver);
	}
	find_orientation_hor(&dist_hor, angle);
	return (dist_hor);
}

t_inter	find_closest_wall(double ray_angle, t_player *player, t_map *map)
{
	t_point	ver_inter;
	t_point	hor_inter;
	t_inter	closest_inter;

	ver_inter = find_v_wall(ray_angle, player, map);
	hor_inter = find_h_wall(ray_angle, player, map);
	closest_inter = find_distance(ver_inter, hor_inter, player->pos, ray_angle);
	return (closest_inter);
}

