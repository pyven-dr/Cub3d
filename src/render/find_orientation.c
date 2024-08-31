/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_orientation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:20:10 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/31 00:20:10 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "render.h"

void	find_orientation_ver(t_inter *inter, double angle, t_map_data *map)
{
	if (get_map_point(inter->point.x, inter->point.y, map) == '2')
		inter->is_door = 1;
	else
		inter->is_door = 0;
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		inter->orientation = WEST;
	else if (angle < M_PI_2 || angle > 3 * M_PI_2)
		inter->orientation = EAST;
}

void	find_orientation_hor(t_inter *inter, double angle, t_map_data *map)
{
	if (get_map_point(inter->point.x, inter->point.y, map) == '2')
		inter->is_door = 1;
	else
		inter->is_door = 0;
	if (angle > M_PI)
		inter->orientation = NORTH;
	else if (angle < M_PI)
		inter->orientation = SOUTH;
}
