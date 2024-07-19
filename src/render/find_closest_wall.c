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
#include "const_values.h"
#include <math.h>

#include <stdio.h>
int find_closest_wall(t_point ver_wall, t_point hor_wall, double ray_angle, t_point *player_pos)
{
	double dist_ver;
	double dist_hor;

	(void)ray_angle;
	 printf("%f %f\n", ver_wall.x, ver_wall.y);
	printf("%f %f\n", hor_wall.x, hor_wall.y);
	dist_ver = sqrt((player_pos->x - ver_wall.x) * (player_pos->x - ver_wall.x) + (player_pos->y - ver_wall.y) * (player_pos->y - ver_wall.y));
	dist_hor = sqrt((player_pos->x - hor_wall.x) * (player_pos->x - hor_wall.x) + (player_pos->y - hor_wall.y) * (player_pos->y - hor_wall.y));
	printf("%f %f %f\n\n", dist_hor, dist_ver, ray_angle);
	if (dist_ver < 0)
		dist_ver = HEIGHT;
	if (dist_hor < 0)
		dist_hor = HEIGHT;
	if (dist_ver < dist_hor)
		return ((int)dist_ver);
	return ((int)dist_hor);
}