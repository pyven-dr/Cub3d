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

#include "render.h"
#include <math.h>

void	find_orientation_ver(t_inter *inter, double ray_angle)
{
	if (ray_angle > M_PI_2 && ray_angle < 3 * M_PI_2)
		inter->orientation = WEST;
	else if (ray_angle < M_PI_2 || ray_angle > 3 * M_PI_2)
		inter->orientation = EAST;
}

void	find_orientation_hor(t_inter *inter, double ray_angle)
{
	if (ray_angle > M_PI)
		inter->orientation = NORTH;
	else if (ray_angle < M_PI)
		inter->orientation = SOUTH;
}
