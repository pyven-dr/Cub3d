/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:30:35 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/27 07:15:50 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "const_values.h"
#include <stddef.h>

void	init_game_data(t_game_data *game_data)
{
	game_data->p.keys.backward = 0;
	game_data->p.keys.forward = 0;
	game_data->p.keys.look_left = 0;
	game_data->p.keys.look_right = 0;
	game_data->p.keys.esc = 0;
	game_data->p.keys.up = 0;
	game_data->p.keys.down = 0;
	game_data->p.keys.left = 0;
	game_data->p.keys.right = 0;
	game_data->p.keys.alt = 0;
	game_data->p.vert_offset = 1;
	game_data->p.player_size = 1;
	game_data->p.keys.hood = 0;
	game_data->p.keys.menu = 1;
	game_data->p.keys.fly = 0;
	game_data->p.keys.crouch = 0;
	game_data->p.keys.map = 0;
	game_data->p.keys.object = 0;
	game_data->p.keys.object_sec = 0;
	game_data->map_data.object.frame_count = 0;
	game_data->map_data.object.current_img = 1;
	game_data->p.keys.mouse.is_recentering = 0;
	game_data->p.keys.mouse.x = WIDTH / 2;
	game_data->p.keys.mouse.y = HEIGHT / 2;
	game_data->map_data.north.path = NULL;
	game_data->map_data.east.path = NULL;
	game_data->map_data.west.path = NULL;
	game_data->map_data.south.path = NULL;
	game_data->map_data.north.img = NULL;
	game_data->map_data.south.img = NULL;
	game_data->map_data.east.img = NULL;
	game_data->map_data.west.img = NULL;
}
