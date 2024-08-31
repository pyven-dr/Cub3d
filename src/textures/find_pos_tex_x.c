/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pos_tex_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 01:46:24 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/30 01:46:24 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	find_pos_tex_x(t_inter *inter, t_map_data *map_data)
{
	if (inter->orientation == NORTH)
	{
		inter->texture_x = (int)((inter->point.x / 64.0) * \
		map_data->north.width) % map_data->north.width;
	}
	if (inter->orientation == SOUTH)
	{
		inter->texture_x = (int)((inter->point.x / 64.0) * \
		map_data->south.width) % map_data->south.width;
		inter->texture_x = (int)inter->texture_x ^ map_data->south.width - 1;
	}
	if (inter->orientation == EAST)
	{
		inter->texture_x = (int)((inter->point.y / 64.0) * \
		map_data->east.width) % map_data->east.width;
	}
	if (inter->orientation == WEST)
	{
		inter->texture_x = (int)((inter->point.y / 64.0) * \
		map_data->west.width) % map_data->west.width;
		inter->texture_x = (int)inter->texture_x ^ map_data->west.width - 1;
	}
}
