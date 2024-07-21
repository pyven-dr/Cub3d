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

#include <stdio.h>
int	find_closest_wall(t_point ver, t_point hor, double angle, t_point *p_pos)
{
	double	dist_ver;
	double	dist_hor;

	printf(" x : %f %f\n", ver.x, ver.y);
	printf("y : %f %f\n", hor.x, hor.y);
	dist_ver = sqrt((ver.x - p_pos->x) * (ver.x - p_pos->x) + \
					(ver.y - p_pos->y) * (ver.y - p_pos->y));
	dist_hor = sqrt((hor.x - p_pos->x) * (hor.x - p_pos->x) + \
					(hor.y - p_pos->y) * (hor.y - p_pos->y));
	printf("dist : %f %f %f %f %f\n\n", dist_hor, dist_ver, angle, p_pos->x, p_pos->y);
	if (dist_ver < 0)
		dist_ver = HEIGHT;
	if (dist_hor < 0)
		dist_hor = HEIGHT;
	if (dist_ver < dist_hor)
		return ((int)dist_ver);
	return ((int)dist_hor);
}
