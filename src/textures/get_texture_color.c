/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:12:53 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/23 00:12:53 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_funcs.h"
#include "render.h"
#include "textures.h"

int	get_texture_color(t_data tex_data, t_inter inter, double pos_tex)
{
	int	tex_x;
	int	tex_y;

	if (inter.orientation == NORTH || inter.orientation == SOUTH)
		tex_x = (int)inter.point.x % 64;
	else
		tex_x = (int)inter.point.y % 64;
	tex_y = (int)pos_tex & 63;
	return (get_pixel_color(tex_data, tex_x, tex_y));
}
