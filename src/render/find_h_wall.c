/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_h_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 03:34:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/13 03:34:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "render.h"
#include <math.h>

static t_point	find_inter(t_point inter, t_true_map *map, double xa, double ya)
{
	int	i;

	i = 0;
	while (i < map->map_height)
	{
		if (get_map_point(inter.x, inter.y, map) == '1')
			return (inter);
		inter.x += xa;
		inter.y += ya;
		i++;
	}
	if (inter.y < 0)
		inter.y = map->map_height * 64 * 2;
	if (inter.x < 0)
		inter.x = map->map_width * 64 * 2;
	return (inter);
}

t_point	find_h_wall(double ray_angle, t_player *player, t_true_map *map)
{
	t_point	inter;
	double	xa;
	double	ya;
	double	atan;

	atan = -1 / tan(ray_angle);
	if (ray_angle > M_PI)
	{
		inter.y = (((int)player->pos->y >> 6) << 6) - 0.0001;
		ya = -64;
	}
	else if (ray_angle < M_PI)
	{
		inter.y = (((int)player->pos->y >> 6) << 6) + 64;
		ya = 64;
	}
	else
	{
		inter.x = player->pos->x;
		inter.y = player->pos->y;
		return (inter);
	}
	inter.x = (player->pos->y - inter.y) * atan + player->pos->x;
	xa = -ya * atan;
	return (find_inter(inter, map, xa, ya));
}
