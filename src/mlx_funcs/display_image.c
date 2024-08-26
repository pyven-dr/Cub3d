/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:26:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 02:26:48 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx_funcs.h"

void	display_img(t_data *img, t_data *background_img)
{
	double x;
	double y;
	double	step_x;
	double	step_y;
	int color;

	y = 0;
	step_x = (double)img->width / WIDTH;
	step_y = (double)img->height / HEIGHT;
	while(y < HEIGHT)
	{
		x = 0;
		while(x < WIDTH)
		{
			color = get_pixel_color(img, (int)(x * step_x), (int)(y * step_y));
			pixel_put(background_img, (int)x, (int)y, color);
			x++;
		}
		y++;
	}
}