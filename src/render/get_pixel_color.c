/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:34:27 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/21 21:34:27 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	get_pixel_color(t_data img_data, int x, int y)
{
	int	offset;
	int	color;

	offset = (y * img_data.line_length) + (x * (img_data.bits_per_pixel / 8));
	if (img_data.endian == 0)
		color = *(unsigned int *)(img_data.addr + offset);
	else
		color = ((unsigned char)(img_data.addr[offset + 0]) << 16) | \
				((unsigned char)(img_data.addr[offset + 1]) << 8) | \
				(unsigned char)(img_data.addr[offset + 2]);
	return (color);
}
