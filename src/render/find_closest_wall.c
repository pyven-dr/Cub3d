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

static t_inter	find_dist(t_point ver, t_point hor, t_point *pos, double angle)
{
	t_inter	dist_ver;
	t_inter	dist_hor;

	dist_ver.distance = sqrt((ver.x - pos->x) * (ver.x - pos->x) + \
					(ver.y - pos->y) * (ver.y - pos->y));
	dist_hor.distance = sqrt((hor.x - pos->x) * (hor.x - pos->x) + \
					(hor.y - pos->y) * (hor.y - pos->y));
	if (dist_ver.distance < 0)
		dist_ver.distance = HEIGHT;
	if (dist_hor.distance < 0)
		dist_hor.distance = HEIGHT;
	if (dist_ver.distance - dist_hor.distance < 0.001 && \
		dist_ver.distance - dist_hor.distance > 0)
	{
		find_orientation_ver(&dist_ver, angle);
		return (dist_ver);
	}
	if (dist_ver.distance < dist_hor.distance)
	{
		find_orientation_ver(&dist_ver, angle);
		return (dist_ver);
	}
	find_orientation_hor(&dist_hor, angle);
	return (dist_hor);
}

t_inter	find_closest_wall(double angle, t_player *player, t_map *map)
{
	t_point	ver_inter;
	t_point	hor_inter;
	t_inter	closest_inter;

	ver_inter = find_v_wall(angle, player, map);
	hor_inter = find_h_wall(angle, player, map);
	closest_inter = find_dist(ver_inter, hor_inter, player->pos, angle);
	return (closest_inter);
}
