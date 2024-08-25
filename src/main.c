/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:18:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 00:48:45 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_funcs.h"
#include "game_loop.h"
#include "check_map.h"
#include "mlx.h"
#include <stdlib.h>
#include "const_values.h"


#include <stdio.h>



int main(int argc, char **argv)
{
	t_game_data	game_data;

	init_game_data(&game_data);
	game_data.mlx_data.mlx_ptr = mlx_init();
	if (game_data.mlx_data.mlx_ptr == NULL)
		return (1);
	if (pre_parsing(argc, argv, &game_data) == -1)
		return (1);
	dprintf(2, "GAME DATA ALT %d", game_data.p.keys.alt);
	if (create_window(&game_data.mlx_data) == 1)
		return (1);
	mlx_mouse_move(game_data.mlx_data.mlx_ptr, game_data.mlx_data.mlx_win, WIDTH / 2, HEIGHT / 2);
	if (new_image(&game_data.mlx_data) == 1)
		return (1);
	game_loop(&game_data);
	return (0);
}
