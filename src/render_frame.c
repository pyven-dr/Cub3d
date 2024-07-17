/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:43:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 00:43:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"
#include "mlx_funcs.h"
#include "render.h"

static void	trace_column(int distance, int column_numb, t_mlx *mlx_data)
{
	int i;
	int	slice_height;
	int	start_wall;

	i = 0;
	if (distance == 0)
		slice_height = PLANE_HEIGHT;
	else
		slice_height = 17728 / distance;
	start_wall = (PLANE_HEIGHT >> 1) - (slice_height >> 1);
	while (i < PLANE_HEIGHT)
	{
		if (i < start_wall)
			pixel_put(mlx_data->img_data, column_numb, i, 0x0062ff);
		else if (i >= start_wall && i <= start_wall + slice_height)
			pixel_put(mlx_data->img_data, column_numb, i, 0xff0011);
		else
			pixel_put(mlx_data->img_data, column_numb, i , 0x05f21d);
		i++;
	}
}

int render_frame(t_map *map, t_player *player, t_mlx *mlx_data)
{
	double	angle;
	double	angle_inc;
	int		closest_wall;
	int		i;

	i = 0;
	angle_inc = player->fov / PLANE_WIDTH;
	angle = normalize_angle(player->angle - (player->fov / 2));
	while (i < PLANE_WIDTH)
	{
		closest_wall = find_closest_wall(find_v_wall(angle, player, map), \
						find_h_wall(angle, player, map), angle, player->pos);
		trace_column(closest_wall, i, mlx_data);
		i++;
		angle = normalize_angle(angle + angle_inc);
	}
	return (0);
}