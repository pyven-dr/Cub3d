/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 05:03:20 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/24 05:03:20 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

void	draw_pixel(t_game_data *g_data, int i, int j, t_inter *inter)
{
	int		*img_data;
	int		img_width;
	t_data	*img[4];

	img[0] = &g_data->map_data.north;
	img[1] = &g_data->map_data.south;
	img[2] = &g_data->map_data.east;
	img[3] = &g_data->map_data.west;
	img_data = (int *)g_data->mlx_data.img_data.addr;
	img_width = g_data->mlx_data.img_data.line_length / sizeof(int);
	if (inter->is_door == 1)
		img_data[i * img_width + j] = get_pixel_color(\
		&g_data->map_data.door, (int)inter->texture_x, (int)inter->texture_y);
	else
		img_data[i * img_width + j] = get_pixel_color(\
		img[inter->orientation], (int)inter->texture_x, (int)inter->texture_y);
}
