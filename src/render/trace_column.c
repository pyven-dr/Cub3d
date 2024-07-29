/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:40:15 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 02:40:15 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx_funcs.h"
#include <stdio.h>

static void draw_wall_color(t_mlx *mlx_data, int i, int j, t_inter inter)
{
	//printf("%d\n", inter.orientation);
	if (inter.orientation == NORTH)
		pixel_put(mlx_data->img_data, j, i, 0xff0011);
	if (inter.orientation == SOUTH)
		pixel_put(mlx_data->img_data, j, i, 0x18ff03);
	if (inter.orientation == EAST)
		pixel_put(mlx_data->img_data, j, i, 0x0320ff);
	if (inter.orientation == WEST)
		pixel_put(mlx_data->img_data, j, i, 0xf2ff03);
}

static void	draw_column_pixels(t_mlx *mlx_data, int j, int w_start, int wall_h, t_inter inter)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i < w_start)
			pixel_put(mlx_data->img_data, j, i, 0x000000);
		else if (i >= w_start && i <= w_start + wall_h)
			draw_wall_color(mlx_data, i, j, inter);
		else
			pixel_put(mlx_data->img_data, j, i, 0xffffff);
		i++;
	}
}

void	trace_column(t_inter inter, int col_numb, t_mlx *mlx_data, int pln_dist)
{
	int		j;
	double	slice_height;
	int		start_wall;
	int		column_size;

	column_size = WIDTH / PLANE_WIDTH;
	if (inter.distance == 0)
		slice_height = PLANE_HEIGHT;
	else
		slice_height = 64 / inter.distance * pln_dist;
	slice_height = slice_height * ((double)HEIGHT / (double)PLANE_HEIGHT);
	if (slice_height > HEIGHT)
		slice_height = HEIGHT;
	start_wall = (HEIGHT >> 1) - ((int)slice_height >> 1);
	j = col_numb * column_size;
	col_numb = j + column_size;
	while (j < col_numb)
	{
		draw_column_pixels(mlx_data, j, start_wall, (int)slice_height, inter);
		j++;
	}
}
