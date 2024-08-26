/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:59:19 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/23 23:59:19 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_funcs.h"

int	get_pixel_color(const t_data *img_data, int x, int y)
{
	int	offset;
	int	color;

	offset = (y * img_data->line_length) + x * (img_data->bits_per_pixel >> 3);
	if (img_data->endian == 0)
		color = *(unsigned int *)(img_data->addr + offset);
	else
		color = ((unsigned char)(img_data->addr[offset + 0]) << 16) | \
				((unsigned char)(img_data->addr[offset + 1]) << 8) | \
				(unsigned char)(img_data->addr[offset + 2]);
	return (color);
}
