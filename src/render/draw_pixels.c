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

static void	draw_wall_color(t_mlx *mlx_data, int i, int j, t_inter inter)
{
	if (inter.orientation == NORTH)
		pixel_put(&mlx_data->img_data, j, i, 0xff0011);
	if (inter.orientation == SOUTH)
		pixel_put(&mlx_data->img_data, j, i, 0x18ff03);
	if (inter.orientation == EAST)
		pixel_put(&mlx_data->img_data, j, i, 0x0320ff);
	if (inter.orientation == WEST)
		pixel_put(&mlx_data->img_data, j, i, 0xf2ff03);
}

void	draw_column(t_mlx *mlx_data, int j, int wall_h, t_inter inter)
{
	int	i;
	int	start_wall;

	i = 0;
	start_wall = (HEIGHT >> 1) - ((int)wall_h >> 1);
	while (i < HEIGHT)
	{
		if (i < start_wall)
			pixel_put(&mlx_data->img_data, j, i, 0x000000);
		else if (i >= start_wall && i <= start_wall + wall_h)
			draw_wall_color(mlx_data, i, j, inter);
		else
			pixel_put(&mlx_data->img_data, j, i, 0xffffff);
		i++;
	}
}
