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
#include "check_map.h"
#include <math.h>

#include <stdlib.h>
#include "mlx.h"

int get_pixel_color(t_data img_data, int x, int y)
{
	int	offset;
	int	color;

	offset = (y * img_data.line_length) + (x * (img_data.bits_per_pixel / 8));
	if (img_data.endian == 0)
		color = *(unsigned int *)(img_data.addr + offset);
	else
		color = ((unsigned char)(img_data.addr[offset + 0]) << 16) |
				((unsigned char)(img_data.addr[offset + 1]) << 8) |
				(unsigned char)(img_data.addr[offset + 2]);
	return (color);
}

int main(int argc, char **argv)
{
	t_game_data	game_data;
	t_true_map	map;
	t_player	player;
	t_point		player_pos;
	t_keys		keys;
	t_mlx		mlx_data;
	t_data		img_data;


	mlx_data.mlx_ptr = mlx_init();
	if (mlx_data.mlx_ptr == NULL)
		return (1);
	game_data.map = &map;
	if (pre_parsing(argc, argv, game_data.map) == -1)
		return (1);
	player.angle = 3.938185;
	player.delta_x = (int)(cos(player.angle) * 1.5);
	player.delta_y = (int)(sin(player.angle) * 1.5);
	player_pos.x = 128;
	player_pos.y = 640;
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