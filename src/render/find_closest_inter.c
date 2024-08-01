/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest_inter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 06:16:12 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/01 06:16:12 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "struct.h"

static int	get_map_point(double x, double y, t_map *map)
{
	if ((int)x >> 6 > map->map_width || (int)y >> 6 > map->map_height)
		return (3);
	return (map->map[((int)(y) >> 6) * map->map_width + ((int)(x) >> 6)]);
}

t_inter	find_closest_inter(t_inter ver, t_inter hor, t_map *map, double angle)
{
	if ((int)ver.distance == (int)hor.distance)
	{
		if (get_map_point(hor.point->x + 32, ver.point->y, map) == 0 || \
			get_map_point(hor.point->x - 32, ver.point->y, map) == 0)
		{
			find_orientation_ver(&ver, angle);
			return (ver);
		}
		if (get_map_point(hor.point->x, ver.point->y + 32, map) == 0 || \
			get_map_point(hor.point->x, ver.point->y - 32, map) == 0)
		{
			find_orientation_hor(&hor, angle);
			return (hor);
		}
	}
	if (ver.distance < hor.distance)
	{
		find_orientation_ver(&ver, angle);
		return (ver);
	}
	find_orientation_hor(&hor, angle);
	return (hor);
}
