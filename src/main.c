/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:18:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/25 22:11:09 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_funcs.h"
#include "game_loop.h"
#include "check_map.h"
#include "mlx.h"
#include <stdlib.h>
#include "const_values.h"

int main(int argc, char **argv)
{
	t_game_data	game_data;

	game_data.mlx_data.mlx_ptr = mlx_init();
	if (game_data.mlx_data.mlx_ptr == NULL)
		return (1);
	if (pre_parsing(argc, argv, &game_data) == -1)
		return (1);
	game_data.p.keys.backward = 0;
	game_data.p.keys.forward = 0;
	game_data.p.keys.look_left = 0;
	game_data.p.keys.look_right = 0;
	game_data.p.keys.esc = 0;
	game_data.p.keys.up = 0;
	game_data.p.keys.down = 0;
	game_data.p.keys.alt = 0;
	game_data.p.vert_offset = 1;
	
	game_data.p.player_size = 1;
	game_data.p.keys.mouse.is_recentering = 0;
	
	if (create_window(&game_data.mlx_data) == 1)
		return (1);
	game_data.p.keys.mouse.x = WIDTH / 2;
	game_data.p.keys.mouse.y = HEIGHT / 2;
	mlx_mouse_move(game_data.mlx_data.mlx_ptr, game_data.mlx_data.mlx_win, WIDTH / 2, HEIGHT / 2);

	if (new_image(&game_data.mlx_data) == 1)
		return (1);
	game_loop(&game_data);
	return (0);
}