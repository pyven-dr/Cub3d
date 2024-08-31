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
#include "textures.h"

static int	check_start_wall(int start_wall, t_inter *inter, double step_tex)
{
	if (start_wall < 0)
	{
		inter->texture_y = -start_wall * step_tex;
		start_wall = 0;
	}
	if (start_wall > HEIGHT)
		start_wall = HEIGHT;
	return (start_wall);
}

static double	get_step_tex(t_map_data *map_data, t_inter *inter, int wall_h)
{
	double	step_tex;
	t_data	*textures[4];

	textures[0] = &map_data->north;
	textures[1] = &map_data->south;
	textures[2] = &map_data->east;
	textures[3] = &map_data->west;
	step_tex = (double)textures[inter->orientation]->width / wall_h;
	return (step_tex);
}

void	draw_column(t_game_data *game_data, int j, int wall_h, t_inter *inter)
{
	int		i;
	int		start_wall;
	int		end_wall;
	double	step_tex;

	i = 0;
	start_wall = ((HEIGHT >> 1) * game_data->p.vert_offset) - \
				(((wall_h) >> 1) * game_data->p.player_size);
	end_wall = start_wall + wall_h;
	find_pos_tex_x(inter, &game_data->map_data);
	step_tex = get_step_tex(&game_data->map_data, inter, wall_h);
	inter->texture_y = 0.0;
	start_wall = check_start_wall(start_wall, inter, step_tex);
	while (i < start_wall)
		pixel_put(&game_data->mlx_data.img_data, j, i++, \
			game_data->map_data.ceiling.hexa);
	while (i < end_wall && i < HEIGHT)
	{
		draw_pixel(game_data, i++, j, inter);
		inter->texture_y += step_tex;
	}
	while (i < HEIGHT)
		pixel_put(&game_data->mlx_data.img_data, j, i++, \
				game_data->map_data.floor.hexa);
}
