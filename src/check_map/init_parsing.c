/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:11:14 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/23 01:44:51 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "stddef.h"

void	init_map(t_map_data *map_data)
{
	map_data->north.path = NULL;
	map_data->south.path = NULL;
	map_data->east.path = NULL;
	map_data->west.path = NULL;
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
}
