/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 05:02:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/24 05:02:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "render.h"
#include "textures.h"

static int	check_start_wall(int start_wall, t_inter *inter, double step_tex)
{
	if (start_wall < 0)
	{
		inter->pos_texture = -start_wall * step_tex;
		start_wall = 0;
	}
	if (start_wall > HEIGHT)
		start_wall = HEIGHT;
	return (start_wall);
}

void	draw_column(t_game_data *game_data, int j, int wall_h, t_inter inter)
{
	int		i;
	int		start_wall;
	int		end_wall;
	double	step_tex;

	i = 0;
	start_wall = ((HEIGHT >> 1) * game_data->p.vert_offset) - \
				(((wall_h) >> 1) * game_data->p.player_size);
	end_wall = start_wall + wall_h;
	step_tex = 64.0 / wall_h;
	inter.pos_texture = 0.0;
	start_wall = check_start_wall(start_wall, &inter, step_tex);
	while (i < start_wall)
		pixel_put(&game_data->mlx_data.img_data, j, i++, \
			game_data->map_data.ceiling.hexa);
	while (i < end_wall && i < HEIGHT)
	{
		draw_pixel(game_data, i++, j, inter);
		inter.pos_texture += step_tex;
	}
	while (i < HEIGHT)
		pixel_put(&game_data->mlx_data.img_data, j, i++, \
				game_data->map_data.floor.hexa);
}
