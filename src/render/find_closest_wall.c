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

int	find_closest_wall(t_point ver, t_point hor, t_point *p_pos)
{
	double	dist_ver;
	double	dist_hor;

	dist_ver = sqrt((ver.x - p_pos->x) * (ver.x - p_pos->x) + \
					(ver.y - p_pos->y) * (ver.y - p_pos->y));
	dist_hor = sqrt((hor.x - p_pos->x) * (hor.x - p_pos->x) + \
					(hor.y - p_pos->y) * (hor.y - p_pos->y));
	if (dist_ver < 0)
		dist_ver = HEIGHT;
	if (dist_hor < 0)
		dist_hor = HEIGHT;
	if (dist_ver < dist_hor)
		return ((int)dist_ver);
	return ((int)dist_hor);
}
