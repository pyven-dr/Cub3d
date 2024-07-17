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

#include "render.h"
#include <math.h>

int find_closest_wall(t_point ver_wall, t_point hor_wall, double ray_angle, t_point player_pos)
{
	int dist_ver;
	int	dist_hor;

	dist_ver = ft_abs((int)((player_pos.x - ver_wall.x) / cos(ray_angle)));
	dist_hor = ft_abs((int)((player_pos.x - hor_wall.x) / cos(ray_angle)));
	if (dist_ver < dist_hor)
		return (dist_ver);
	return (dist_hor);
}