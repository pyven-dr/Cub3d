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

static void	draw_column_pixels(t_mlx *mlx_data, int j, int start_wall, int slice_height)
{
	int	i;

	i = 0;
	while (i < HEIGHT)
	{
		if (i < start_wall)
			pixel_put(mlx_data->img_data, j, i, 0x0062ff);
		else if (i >= start_wall && i <= start_wall + slice_height)
			pixel_put(mlx_data->img_data, j, i, 0xff0011);
		else
			pixel_put(mlx_data->img_data, j, i , 0x05f21d);
		i++;
	}
}

#include <stdio.h>

void	trace_column(int distance, int column_numb, t_mlx *mlx_data)
{
	int		j;
	int		slice_height;
	int		start_wall;
	int		column_size;

	column_size = WIDTH / PLANE_WIDTH;
	printf("distance %d\n", distance);
	if (distance == 0)
		slice_height = PLANE_HEIGHT;
	else
		slice_height = (int)((64 / (double)distance) * 277);
	printf("%d\n", slice_height);
	slice_height = (int)((double)slice_height * (540.0 / 200.0));
	printf("%d\n", slice_height);
	if (slice_height > HEIGHT)
		slice_height = HEIGHT;
	start_wall = (HEIGHT >> 1) - ((int)slice_height >> 1);
	printf("%d slice_height %d\n", start_wall, slice_height);
	j = column_numb * column_size;
	column_numb = j + column_size;
	while (j < column_numb)
	{
		draw_column_pixels(mlx_data, j, start_wall, (int)slice_height);
		j++;
	}
}