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

int	get_texture_color(const t_data *tex_data, t_inter inter, double pos_tex)
{
	int	tex_x;

	if (inter.orientation == NORTH || inter.orientation == SOUTH)
		tex_x = (int)inter.point.x & 63;
	else
		tex_x = (int)inter.point.y & 63;
	return (get_pixel_color(tex_data, tex_x, pos_tex));
}
