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

static void	draw_column_pixels(t_mlx *mlx_data, int j, int w_start, int wall_h)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i < w_start)
			pixel_put(mlx_data->img_data, j, i, 0x0062ff);
		else if (i >= w_start && i <= w_start + wall_h)
			pixel_put(mlx_data->img_data, j, i, 0xff0011);
		else
			pixel_put(mlx_data->img_data, j, i, 0x05f21d);
		i++;
	}
}

void	trace_column(double dist, int col_numb, t_mlx *mlx_data, int pln_dist)
{
	int		j;
	double	slice_height;
	int		start_wall;
	int		column_size;

	column_size = WIDTH / PLANE_WIDTH;
	if (dist == 0)
		slice_height = PLANE_HEIGHT;
	else
		slice_height = 64 / dist * pln_dist;
	slice_height = slice_height * ((double)HEIGHT / (double)PLANE_HEIGHT);
	if (slice_height > HEIGHT)
		slice_height = HEIGHT;
	start_wall = (HEIGHT >> 1) - ((int)slice_height >> 1);
	j = col_numb * column_size;
	col_numb = j + column_size;
	while (j < col_numb)
	{
		draw_column_pixels(mlx_data, j, start_wall, (int)slice_height);
		j++;
	}
}
