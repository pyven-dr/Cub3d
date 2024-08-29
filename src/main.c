/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:18:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 07:12:32 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check_map.h"
#include "ft_printf.h"
#include "mlx.h"

static int	create_img_win(t_game_data *game_data)
{
	if (create_window(&game_data->mlx_data) == 1)
	{
		free_img(game_data->mlx_data.mlx_ptr, &game_data->map_data);
		free_parsing(game_data);
		return (1);
	}
	if (new_image(&game_data->mlx_data) == 1)
	{
		free_img(game_data->mlx_data.mlx_ptr, &game_data->map_data);
		mlx_destroy_window(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.mlx_win);
		free_parsing(game_data);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game_data	game_data;

	if (argc != 2)
	{
		ft_printf(2, "Wrong number of arguments\n");
		return (1);
	}
	game_data.mlx_data.mlx_ptr = mlx_init();
	if (game_data.mlx_data.mlx_ptr == NULL)
		return (1);
	init_game_data(&game_data);
	if (pre_parsing(argv, &game_data) == -1)
	{
		free_parsing(&game_data);
		return (1);
	}
	if (open_img(&game_data.map_data, game_data.mlx_data.mlx_ptr) == 1)
	{
		free_parsing(&game_data);
		return (1);
	}
	if (create_img_win(&game_data) == 1)
		return (1);
	game_loop(&game_data);
	return (0);
}
