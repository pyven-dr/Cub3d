/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:18:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 04:18:28 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx_funcs.h"
#include "game_loop.h"
#include "const_values.h"
#include <math.h>
#include <stdlib.h>

int main(void)
{
	t_game_data	game_data;
	t_map		map;
	t_player	player;
	t_point		player_pos;
	t_keys		keys;
	t_mlx		mlx_data;
	t_data		img_data;

	int map_array[] = {1, 1, 1, 1, 1, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 1, 0, 0, 1,
					   1, 0, 0, 1, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 1, 1, 1, 1, 1};

	map.map_height = 9;
	map.map_width = 6;
	map.map = map_array;
	game_data.map = &map;

	player.angle = 3.938185;
	player.delta_x = (int)(cos(player.angle) * 1.5);
	player.delta_y = (int)(sin(player.angle) * 1.5);
	player_pos.x = 193.969050;
	player_pos.y = 384.276566;
	player.fov = FOV * (M_PI / 180);
	player.plane_dist = (int)((PLANE_WIDTH / 2.0) / tan(player.fov / 2));
	player.pos = &player_pos;

	keys.backward = 0;
	keys.forward = 0;
	keys.left = 0;
	keys.right = 0;
	keys.esc = 0;
	player.keys = &keys;

	game_data.player = &player;
	img_data.img = NULL;
	mlx_data.img_data = &img_data;
	game_data.mlx_data = &mlx_data;
	if (create_window(game_data.mlx_data) == 1)
		return (1);
	if (new_image(game_data.mlx_data) == 1)
		return (1);
	game_loop(&game_data);
	return (0);
}