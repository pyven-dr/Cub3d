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

#include "mlx.h"
#include "struct.h"
#include "mlx_funcs.h"
#include "game_loop.h"
#include "const_values.h"
#include <stdlib.h>
#include <math.h>

int main(void)
{
	t_mlx			mlx_data;
	t_data			img_data;
	t_pressed_key	key;
	t_player		player;
	t_map			map;
	int map_array[] = {1, 1, 1, 1, 1, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 0, 0, 0, 0, 1,
					   1, 1, 1, 1, 1, 1};

	map.map_height = 6;
	map.map_width = 6;
	map.map = map_array;

	player.angle = M_PI;
	player.pos.x = 160;
	player.pos.y = 160;
	player.fov = FOV * (M_PI / 180);

	key.backward = 0;
	key.forward = 0;
	key.left = 0;
	key.right = 0;
	mlx_data.img_data = &img_data;
	if (create_window(&mlx_data) == 1)
		return (1);
	if (new_image(&mlx_data) == 1)
	{
		mlx_destroy_window(mlx_data.mlx_ptr, mlx_data.mlx_win);
		mlx_destroy_display(mlx_data.mlx_ptr);
		free(mlx_data.mlx_ptr);
		return (1);
	}
	render_frame(&map, &player, &mlx_data);
	mlx_put_image_to_window(mlx_data.mlx_ptr, mlx_data.mlx_win, mlx_data.img_data->img, 0, 0);
	game_loop(&mlx_data, &key);
	return (0);
}