/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:11:14 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/24 01:25:28 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "stddef.h"
#include "stdlib.h"
#include "mlx.h"

void	free_parsing(t_game_data *game_data)
{
	int	i;

	i = 0;
	if (game_data->map_data.north.path != NULL)
		free(game_data->map_data.north.path);
	if (game_data->map_data.south.path != NULL)
		free(game_data->map_data.south.path);
	if (game_data->map_data.east.path != NULL)
		free(game_data->map_data.east.path);
	if (game_data->map_data.west.path != NULL)
		free(game_data->map_data.west.path);
	if (game_data->map_data.pb && game_data->map_data.map != NULL)
	{
		while (i < game_data->map_data.map_height && i < game_data->map_data.pb)
				free(game_data->map_data.map[i++]);
	}
	free(game_data->map_data.map);
	if (game_data->map_data.north.img)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr, game_data->map_data.north.img);
	if (game_data->map_data.south.img)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr, game_data->map_data.south.img);
	if (game_data->map_data.east.img)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr, game_data->map_data.east.img);
	if (game_data->map_data.west.img)
		mlx_destroy_image(game_data->mlx_data.mlx_ptr, game_data->map_data.west.img);
	mlx_destroy_display(game_data->mlx_data.mlx_ptr);
	free(game_data->mlx_data.mlx_ptr);
}

void	init_map(t_map_data *map_data)
{
	map_data->north.path = NULL;
	map_data->south.path = NULL;
	map_data->east.path = NULL;
	map_data->west.path = NULL;
	map_data->map = NULL;
	map_data->ceiling.hexa = 0;
	map_data->ceiling.r = 0;
	map_data->ceiling.g = 0;
	map_data->ceiling.b = 0;
	map_data->floor.hexa = 0;
	map_data->floor.r = 0;
	map_data->floor.g = 0;
	map_data->floor.b = 0;
	map_data->map_height = 0;
	map_data->map_width = 0;
	map_data->number_player = 0;
	map_data->pb = 0;
}
