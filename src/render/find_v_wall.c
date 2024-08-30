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

#include <math.h>
#include "render.h"

static t_point	find_inter(t_point inter, t_map_data *map, double xa, double ya)
{
	int	i;

	i = 0;
	while (i < map->map_width)
	{
		if (get_map_point(inter.x, inter.y, map) == '1' || \
			get_map_point(inter.x, inter.y, map) == '2')
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

t_point	find_v_wall(double ray_angle, t_player *player, t_map_data *map)
{
	t_point	inter;
	double	xa;
	double	ya;
	double	ntan;

	ntan = -tan(ray_angle);
	if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
	{
		inter.x = (((int)player->pos.x >> 6) << 6) - 0.0001;
		xa = -64;
	}
	else if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
	{
		inter.x = (((int)player->pos.x >> 6) << 6) + 64;
		xa = 64;
	}
	else
	{
		inter.y = player->pos.y;
		inter.x = player->pos.x;
		return (inter);
	}
	inter.y = (player->pos.x - inter.x) * ntan + player->pos.y;
	ya = -xa * ntan;
	return (find_inter(inter, map, xa, ya));
}
