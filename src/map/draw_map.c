/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 00:53:51 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 00:53:51 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "render.h"

void	draw_map(t_game_data *game_data)
{
	t_point	origin;
	int		tile_size;
	int		i;
	int		j;

	origin.x = game_data->p.pos.x - (MINIMAP_RANGE << 6);
	origin.y = game_data->p.pos.y - (MINIMAP_RANGE << 6);
	tile_size = (WIDTH >> 1) / MINIMAP_RANGE / 3;
	display_img(&game_data->map_data.map_img, \
	&game_data->mlx_data.img_data);
	i = 0;
	while (i < MINIMAP_RANGE << 1)
	{
		j = 0;
		while (j < MINIMAP_RANGE << 1)
		{
			if (get_map_point(origin.x + (j << 6), origin.y + (i << 6), \
			&game_data->map_data) == '1')
				draw_square(&game_data->mlx_data.img_data, (i * tile_size) + \
				(HEIGHT / 5), (j * tile_size) + (WIDTH / 3), tile_size);
			j++;
		}
		i++;
	}
	draw_player(&game_data->mlx_data.img_data, tile_size);
}
