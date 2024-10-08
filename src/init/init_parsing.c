/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:11:14 by tcoze             #+#    #+#             */
/*   Updated: 2024/09/01 03:01:59 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "check_map.h"
#include "mlx.h"

static void	free_img_parsing(t_game_data *g_data)
{
	if (g_data->map_data.north.img)
		mlx_destroy_image(g_data->mlx_data.mlx_ptr, g_data->map_data.north.img);
	if (g_data->map_data.south.img)
		mlx_destroy_image(g_data->mlx_data.mlx_ptr, g_data->map_data.south.img);
	if (g_data->map_data.east.img)
		mlx_destroy_image(g_data->mlx_data.mlx_ptr, g_data->map_data.east.img);
	if (g_data->map_data.west.img)
		mlx_destroy_image(g_data->mlx_data.mlx_ptr, g_data->map_data.west.img);
	if (g_data->map_data.door.img)
		mlx_destroy_image(g_data->mlx_data.mlx_ptr, g_data->map_data.door.img);
	mlx_destroy_display(g_data->mlx_data.mlx_ptr);
	free(g_data->mlx_data.mlx_ptr);
}

void	free_parsing(t_game_data *g_data)
{
	int	i;

	i = 0;
	if (g_data->map_data.north.path != NULL)
		free(g_data->map_data.north.path);
	if (g_data->map_data.south.path != NULL)
		free(g_data->map_data.south.path);
	if (g_data->map_data.east.path != NULL)
		free(g_data->map_data.east.path);
	if (g_data->map_data.west.path != NULL)
		free(g_data->map_data.west.path);
	if (g_data->map_data.door.path != NULL)
		free(g_data->map_data.door.path);
	if (g_data->map_data.pb && g_data->map_data.map != NULL)
		while (i < g_data->map_data.map_height && i < g_data->map_data.pb)
			free(g_data->map_data.map[i++]);
	free(g_data->map_data.map);
	free_img_parsing(g_data);
}

void	init_map(t_map_data *map_data)
{
	map_data->north.path = NULL;
	map_data->south.path = NULL;
	map_data->east.path = NULL;
	map_data->west.path = NULL;
	map_data->door.path = NULL;
	map_data->map = NULL;
	map_data->ceiling.hexa = -1;
	map_data->ceiling.r = 0;
	map_data->ceiling.g = 0;
	map_data->ceiling.b = 0;
	map_data->floor.hexa = -1;
	map_data->floor.r = 0;
	map_data->floor.g = 0;
	map_data->floor.b = 0;
	map_data->map_height = 0;
	map_data->map_width = 0;
	map_data->number_player = 0;
	map_data->pb = 0;
}
