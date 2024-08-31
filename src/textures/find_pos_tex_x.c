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

static void	invert_tex(t_inter *inter, t_map_data *map)
{
	if (inter->orientation == SOUTH)
	{
		if (inter->is_door == 1)
			inter->texture_x = (int)inter->texture_x ^ map->door.width - 1;
		else
			inter->texture_x = (int)inter->texture_x ^ map->south.width - 1;
	}
	else if (inter->orientation == WEST)
	{
		if (inter->is_door == 1)
			inter->texture_x = (int) inter->texture_x ^ map->door.width - 1;
		else
			inter->texture_x = (int)inter->texture_x ^ map->west.width - 1;
	}
}

void	find_pos_tex_x(t_inter *inter, t_map_data *map_data)
{
	t_data	*img[4];

	img[0] = &map_data->north;
	img[1] = &map_data->south;
	img[2] = &map_data->east;
	img[3] = &map_data->west;
	if (inter->orientation == NORTH || inter->orientation == SOUTH)
	{
		if (inter->is_door == 1)
			inter->texture_x = (int)((inter->point.x / 64.0) * \
			map_data->door.width) % map_data->door.width;
		else
			inter->texture_x = (int)((inter->point.x / 64.0) * \
			img[inter->orientation]->width) % img[inter->orientation]->width;
	}
	if (inter->orientation == EAST || inter->orientation == WEST)
	{
		if (inter->is_door == 1)
			inter->texture_x = (int)((inter->point.y / 64.0) * \
			map_data->door.width) % map_data->door.width;
		else
			inter->texture_x = (int)((inter->point.y / 64.0) * \
			img[inter->orientation]->width) % img[inter->orientation]->width;
	}
	invert_tex(inter, map_data);
}
