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

static t_inter	find_dist(t_point inter_point, t_point *pos)
{
	t_inter	inter;

	inter.distance = sqrt((inter_point.x - pos->x) * (inter_point.x - pos->x) \
						+ (inter_point.y - pos->y) * (inter_point.y - pos->y));
	if (inter.distance < 0)
		inter.distance = HEIGHT;
	inter.point = inter_point;
	return (inter);
}

t_inter	find_closest_wall(double angle, t_player *player, t_map_data *map)
{
	t_inter	ver_inter;
	t_inter	hor_inter;
	t_inter	closest_inter;

	ver_inter = find_dist(find_v_wall(angle, player, map), &player->pos);
	hor_inter = find_dist(find_h_wall(angle, player, map), &player->pos);
	closest_inter = find_clos_inter(ver_inter, hor_inter, map, angle);
	return (closest_inter);
}
