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

int	get_texture_color(t_data tex_data, t_inter inter, double pos_tex)
{
	int tex_x;
	int tex_y;

	if (inter.orientation == NORTH || inter.orientation == SOUTH)
		tex_x = (int)inter.point.x % 64;
	else
		tex_x = (int)inter.point.y % 64;
	tex_y = (int)pos_tex & 63;
	return (get_pixel_color(tex_data, tex_x, tex_y));
}

static void	draw_wall_color(t_game_data *game_data, int i, int j, t_inter inter, double pos_tex)
{
	if (inter.orientation == NORTH)
		pixel_put(&game_data->mlx_data.img_data, j, i, get_texture_color(game_data->map_data.north, inter, pos_tex));
	if (inter.orientation == SOUTH)
		pixel_put(&game_data->mlx_data.img_data, j, i, get_texture_color(game_data->map_data.south, inter, pos_tex));
	if (inter.orientation == EAST)
		pixel_put(&game_data->mlx_data.img_data, j, i, get_texture_color(game_data->map_data.east, inter, pos_tex));
	if (inter.orientation == WEST)
		pixel_put(&game_data->mlx_data.img_data, j, i, get_texture_color(game_data->map_data.west, inter, pos_tex));
}

void	draw_column(t_game_data *game_data, int j, int wall_h, t_inter inter)
{
	int		i;
	int		start_wall;
	double	step_tex;
	double	pos_tex;

	i = 0;
	start_wall = (HEIGHT >> 1) - ((int)wall_h >> 1);
	step_tex = (double)64 / wall_h;
	pos_tex = 0.0;
	if (start_wall < 0)
		pos_tex = -start_wall * step_tex;
	while (i < HEIGHT)
	{
		if (i < start_wall)
			pixel_put(&game_data->mlx_data.img_data, j, i, game_data->map_data.ceiling.hexa);
		else if (i >= start_wall && i <= start_wall + wall_h)
		{
			draw_wall_color(game_data, i, j, inter, pos_tex);
			pos_tex += step_tex;
		}
		else
			pixel_put(&game_data->mlx_data.img_data, j, i, game_data->map_data.floor.hexa);
		i++;
	}
}
