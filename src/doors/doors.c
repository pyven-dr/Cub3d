/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 04:31:16 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/30 04:31:16 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "const_values.h"
#include "player.h"
#include "render.h"

void	check_doors_map(t_player *player, t_map_data *map_data, int x, int y)
{
	if (get_map_point(x, y, map_data) == '2')
	{
		if (player->keys.door == 1)
			map_data->map[(int)floor(y) >> 6][(int)floor(x) >> 6] = '3';
	}
	else if (get_map_point(x, y, map_data) == '3')
	{
		if (player->keys.door == 1)
			map_data->map[(int)floor(y) >> 6][(int)floor(x) >> 6] = '2';
	}
}

void	check_doors(t_player *player, t_map_data *map_data)
{
	if (player->angle > 5 * M_PI / 4 && player->angle < 7 * M_PI / 4)
		check_doors_map(player, map_data, player->pos.x, \
		player->pos.y - 64 - COLLISION_OFFSET);
	else if (player->angle > M_PI / 4 && player->angle < 3 * M_PI / 4)
		check_doors_map(player, map_data, player->pos.x, \
		player->pos.y + 64 + COLLISION_OFFSET);
	else if (player->angle > 7 * M_PI / 4 || player->angle < M_PI / 4)
		check_doors_map(player, map_data, \
		player->pos.x + 64 + COLLISION_OFFSET, player->pos.y);
	else if (player->angle > 3 * M_PI / 4 && player->angle < 5 * M_PI / 4)
		check_doors_map(player, map_data, \
		player->pos.x - 64 - COLLISION_OFFSET, player->pos.y);
	player->keys.door = 0;
}
