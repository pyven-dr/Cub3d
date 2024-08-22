/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 00:58:35 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/31 00:58:35 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx_funcs.h"
#include "struct.h"
#include "textures.h"

static void	draw_wall_color(t_game_data *game_data, int i, int j, t_inter inter)
{
	if (inter.orientation == NORTH)
		pixel_put(&game_data->mlx_data.img_data, j, i, \
		get_texture_color(game_data->map_data.north, inter, inter.pos_texture));
	if (inter.orientation == SOUTH)
		pixel_put(&game_data->mlx_data.img_data, j, i, \
		get_texture_color(game_data->map_data.south, inter, inter.pos_texture));
	if (inter.orientation == EAST)
		pixel_put(&game_data->mlx_data.img_data, j, i, \
		get_texture_color(game_data->map_data.east, inter, inter.pos_texture));
	if (inter.orientation == WEST)
		pixel_put(&game_data->mlx_data.img_data, j, i, \
		get_texture_color(game_data->map_data.west, inter, inter.pos_texture));
}

void	draw_column(t_game_data *game_data, int j, int wall_h, t_inter inter)
{
	int		i;
	int		start_wall;
	double	step_tex;

	i = 0;
	start_wall = (HEIGHT >> 1) - ((int)wall_h >> 1);
	step_tex = (double)64 / wall_h;
	inter.pos_texture = 0.0;
	if (start_wall < 0)
		inter.pos_texture = -start_wall * step_tex;
	while (i < HEIGHT)
	{
		if (i < start_wall)
			pixel_put(&game_data->mlx_data.img_data, j, i, \
				game_data->map_data.ceiling.hexa);
		else if (i >= start_wall && i <= start_wall + wall_h)
		{
			draw_wall_color(game_data, i, j, inter);
			inter.pos_texture += step_tex;
		}
		else
			pixel_put(&game_data->mlx_data.img_data, j, i, \
				game_data->map_data.floor.hexa);
		i++;
	}
}
