/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_v_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:40:09 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 00:40:09 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <math.h>

static t_point	find_inter(t_point inter, t_map *map, double xa, double ya)
{
	int	i;

	i = 0;
	while (i < map->map_width)
	{
		inter.map_point = ((int)(inter.y) >> 6) * map->map_width + \
							((int)(inter.x) >> 6);
		if (inter.map_point >= 0 && inter.map_point < map->map_width * \
			map->map_height - 1 && map->map[inter.map_point] == 1)
			return (inter);
		inter.x += xa;
		inter.y += ya;
		i++;
	}
	if (inter.x < 0)
		inter.x = map->map_width * 64 * 2;
	if (inter.y < 0)
		inter.y = map->map_height * 64 * 2;
	return (inter);
}

t_point	find_v_wall(double ray_angle, t_player *player, t_map *map)
{
	t_point	inter;
	double	xa;
	double	ya;
	double	ntan;

	ntan = -tan(ray_angle);
	if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
	{
		inter.x = (((int)player->pos->x >> 6) << 6) - 0.0001;
		xa = -64;
	}
	else if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
	{
		inter.x = (((int)player->pos->x >> 6) << 6) + 64;
		xa = 64;
	}
	else
	{
		inter.y = player->pos->y;
		inter.x = player->pos->x;
		return (inter);
	}
	inter.y = (player->pos->x - inter.x) * ntan + player->pos->y;
	ya = -xa * ntan;
	return (find_inter(inter, map, xa, ya));
}
