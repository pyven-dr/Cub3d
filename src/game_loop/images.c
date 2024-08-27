/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:48:17 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 06:48:17 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"

int	switch_img(int current_frame)
{
	if (current_frame == 3)
		current_frame = 1;
	else
		current_frame++;
	return (current_frame);
}

void	display_object(t_object *object, t_data *img_data)
{
	if (object->frame_count == OBJ_FRAME_NB)
	{
		object->frame_count = 0;
		object->current_img = switch_img(object->current_img);
	}
	if (object->current_img == 1)
		display_img(&object->object_use1, img_data);
	if (object->current_img == 2)
		display_img(&object->object_use2, img_data);
	if (object->current_img == 3)
		display_img(&object->object_use3, img_data);
	object->frame_count++;
}

void	display_images(t_game_data *game_data)
{
	if (game_data->p.keys.map == 1)
		draw_map(game_data);
	else
	{
		if (game_data->p.keys.object_sec == 1)
			display_img(&game_data->map_data.object.object_use_sec, \
			&game_data->mlx_data.img_data);
		else if (game_data->p.keys.object == 0)
			display_img(&game_data->map_data.object.object_idle, \
			&game_data->mlx_data.img_data);
		else
			display_object(&game_data->map_data.object, \
							&game_data->mlx_data.img_data);
	}
	if (game_data->p.keys.hood == 1)
		display_img(&game_data->map_data.hood, \
			&game_data->mlx_data.img_data);
}
