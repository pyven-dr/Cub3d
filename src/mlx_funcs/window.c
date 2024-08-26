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

#include "const_values.h"
#include "mlx.h"
#include "mlx_funcs.h"
#include "game_loop.h"
#include <stdlib.h>

void	free_img(void *mlx_ptr, t_map_data *map_data)
{
	mlx_destroy_image(mlx_ptr, map_data->menu.img);
	mlx_destroy_image(mlx_ptr, map_data->hood.img);
	mlx_destroy_image(mlx_ptr, map_data->north.img);
	mlx_destroy_image(mlx_ptr, map_data->south.img);
	mlx_destroy_image(mlx_ptr, map_data->east.img);
	mlx_destroy_image(mlx_ptr, map_data->west.img);
	free(map_data->north.path);
	free(map_data->south.path);
	free(map_data->east.path);
	free(map_data->west.path);
}

int	close_window(void *struct_data)
{
	t_game_data	*game_data;
	int			i;

	i = 0;
	game_data = (t_game_data *)struct_data;
	free_img(game_data->mlx_data.mlx_ptr, &game_data->map_data);
	while (i < game_data->map_data.map_height && i < game_data->map_data.pb)
		free(game_data->map_data.map[i++]);
	free(game_data->map_data.map);
	mlx_destroy_image(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.img_data.img);
	mlx_destroy_window(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.mlx_win);
	mlx_destroy_display(game_data->mlx_data.mlx_ptr);
	free(game_data->mlx_data.mlx_ptr);
	exit(0);
}

int	create_window(t_mlx *mlx_data)
{
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx_ptr, WIDTH, \
									HEIGHT, WIN_NAME);
	if (mlx_data->mlx_win == NULL)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		return (1);
	}
	return (0);
}
