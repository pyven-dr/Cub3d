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

#include "render.h"
#include "textures.h"

void	draw_pixel(t_game_data *game_data, int i, int j, t_inter inter)
{
	int		*img_data;
	int		img_width;
	t_data	*textures[4];

	textures[0] = &game_data->map_data.north;
	textures[1] = &game_data->map_data.south;
	textures[2] = &game_data->map_data.east;
	textures[3] = &game_data->map_data.west;
	img_data = (int *)game_data->mlx_data.img_data.addr;
	img_width = game_data->mlx_data.img_data.line_length / sizeof(int);
	img_data[i * img_width + j] = get_texture_color(\
	textures[inter.orientation], inter, (int)inter.pos_texture);
}
