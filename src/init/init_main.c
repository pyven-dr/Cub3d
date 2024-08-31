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

#include <stdlib.h>
#include "const_values.h"
#include "game_loop.h"

static void	init_keys(t_keys *keys)
{
	keys->backward = 0;
	keys->forward = 0;
	keys->look_left = 0;
	keys->look_right = 0;
	keys->esc = 0;
	keys->up = 0;
	keys->down = 0;
	keys->left = 0;
	keys->right = 0;
	keys->alt = 0;
	keys->hood = 0;
	keys->menu = 1;
	keys->fly = 0;
	keys->crouch = 0;
	keys->map = 0;
	keys->object = 0;
	keys->object_sec = 0;
	keys->door = 0;
	keys->mouse.is_recentering = 0;
	keys->mouse.x = WIDTH / 2;
	keys->mouse.y = HEIGHT / 2;
}

static void	init_map_data(t_map_data *map_data)
{
	map_data->object.frame_count = 0;
	map_data->object.current_img = 1;
	map_data->north.path = NULL;
	map_data->east.path = NULL;
	map_data->west.path = NULL;
	map_data->south.path = NULL;
	map_data->north.img = NULL;
	map_data->south.img = NULL;
	map_data->east.img = NULL;
	map_data->west.img = NULL;
	map_data->door.img = NULL;
	map_data->object.object_idle.img = NULL;
	map_data->object.object_use1.img = NULL;
	map_data->object.object_use2.img = NULL;
	map_data->object.object_use3.img = NULL;
	map_data->object.object_use_sec.img = NULL;
	map_data->menu.img = NULL;
	map_data->hood.img = NULL;
	map_data->map_img.img = NULL;
}

static void	init_player(t_player *player)
{
	player->vert_offset = 1;
	player->player_size = 1;
}

void	init_game_data(t_game_data *game_data)
{
	init_keys(&game_data->p.keys);
	init_map_data(&game_data->map_data);
	init_player(&game_data->p);
}
