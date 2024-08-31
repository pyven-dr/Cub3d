/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:25:50 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 21:25:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx_funcs.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIDTH || y > HEIGHT)
		return ;
	if (color == (int)0xFF000000)
		return ;
	dst = data->addr + (y * data->line_length + x * \
			(data->bits_per_pixel >> 3));
	*(unsigned int *)dst = color;
}
