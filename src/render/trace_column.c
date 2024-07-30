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
#include "render.h"

void	trace_column(t_inter inter, int col_numb, t_mlx *mlx_data, int pln_dist)
{
	int		j;
	double	slice_height;
	int		column_size;

	column_size = WIDTH / PLANE_WIDTH;
	if (inter.distance == 0)
		slice_height = PLANE_HEIGHT;
	else
		slice_height = 64 / inter.distance * pln_dist;
	slice_height = slice_height * ((double)HEIGHT / (double)PLANE_HEIGHT);
	if (slice_height > HEIGHT)
		slice_height = HEIGHT;
	j = col_numb * column_size;
	col_numb = j + column_size;
	while (j < col_numb)
	{
		draw_column(mlx_data, j, (int) slice_height, inter);
		j++;
	}
}
