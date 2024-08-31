/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:54:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 23:54:48 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "const_values.h"
#include "mlx.h"
#include <stdlib.h>

int	close_window(void *struct_data)
{
	t_game_data	*game_data;

	game_data = (t_game_data *)struct_data;
	free_img(game_data->mlx_data.mlx_ptr, &game_data->map_data);
	mlx_destroy_image(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.img_data.img);
	mlx_destroy_window(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.mlx_win);
	free_parsing(game_data);
	exit(0);
}

int	create_window(t_mlx *mlx_data)
{
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx_ptr, WIDTH, \
								HEIGHT, WIN_NAME);
	if (mlx_data->mlx_win == NULL)
		return (1);
	return (0);
}
