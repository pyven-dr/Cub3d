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

t_point	find_v_wall(double ray_angle, t_player *player, t_map *map)
{
	t_point first_inter;
	double	xa;
	double	ya;
	double	nTan;
	int		dof;

	dof = 0;
	nTan = -tan(ray_angle);
	if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
	{
		first_inter.x = (((int)player->pos->x >> 6) << 6) - 0.0001;
		first_inter.y = (player->pos->x - first_inter.x) * nTan + player->pos->y;
		xa = -64;
		ya = -xa * nTan;
	}
	else if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
	{
		first_inter.x = (((int)player->pos->x >> 6) << 6) + 64;
		first_inter.y = (player->pos->x - first_inter.x) * nTan + player->pos->y;
		xa = 64;
		ya = -xa * nTan;
	}
	else
	{
		first_inter.y = player->pos->y;
		first_inter.x = player->pos->x;
		dof = map->map_width;
	}
	while (dof < map->map_width)
	{
		first_inter.map_point = ((int)(first_inter.y) >> 6) * map->map_width + ((int)(first_inter.x) >> 6);
		if (first_inter.map_point >= 0 && first_inter.map_point < map->map_width * map->map_height - 1 && map->map[first_inter.map_point] == 1)
			return (first_inter);
		first_inter.x += xa;
		first_inter.y += ya;
		dof++;
	}
	if (first_inter.x < 0)
		first_inter.x = map->map_width * 64 * 2;
	if (first_inter.y < 0)
		first_inter.y = map->map_height * 64 * 2;
	return (first_inter);
}