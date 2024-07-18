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
#include <math.h>

t_point	find_h_wall(double ray_angle, t_player *player, t_map *map)
{
	t_point first_inter;
	double	xa;
	double	ya;
	double	aTan;
	int		dof;

	dof = 0;
	aTan = -1 / tan(ray_angle);
	if (ray_angle > M_PI)
	{
		first_inter.y = (((int)player->pos.y >> 6) << 6) - 0.0001;
		first_inter.x = (player->pos.x - first_inter.y) * aTan + player->pos.x;
		ya = -64;
		xa = -ya * aTan;
	}
	else if (ray_angle < M_PI)
	{
		first_inter.y = (((int)player->pos.y >> 6) << 6) + 64;
		first_inter.x = (player->pos.x - first_inter.y) * aTan + player->pos.x;
		ya = 64;
		xa = -ya * aTan;
	}
	else
	{
		first_inter.x = player->pos.x;
		first_inter.y = player->pos.y;
		dof = 8;
	}
	while (dof < map->map_height)
	{
		first_inter.map_point = ((int)(first_inter.y) >> 6) * map->map_width + ((int)(first_inter.x) >> 6);
		if (first_inter.map_point > 0 && first_inter.map_point < map->map_width * map->map_height && map->map[first_inter.map_point] == 1)
			return (first_inter);
		first_inter.x += xa;
		first_inter.y += ya;
		dof++;
	}
	return (first_inter);
}
