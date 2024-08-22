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

#include "mlx_funcs.h"
#include "game_loop.h"
#include "check_map.h"
#include "mlx.h"
#include <stdlib.h>

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
	game_data.p.keys.left = 0;
	game_data.p.keys.right = 0;
	game_data.p.keys.esc = 0;

	if (create_window(&game_data.mlx_data) == 1)
		return (1);
	if (new_image(&game_data.mlx_data) == 1)
		return (1);
	game_loop(&game_data);
	return (0);
}