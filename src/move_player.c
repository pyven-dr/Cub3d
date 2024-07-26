/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:48:18 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/21 10:48:18 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "struct.h"

static int	check_out_map(t_player *player, t_map *map)
{
	if (map->map[((int)(player->pos->y + COLLISION_OFFSET) >> 6) * \
		map->map_width + ((int)(player->pos->x) >> 6)] == 1)
		return (1);
	if (map->map[((int)(player->pos->y - COLLISION_OFFSET) >> 6) * \
		map->map_width + ((int)(player->pos->x) >> 6)] == 1)
		return (1);
	if (map->map[((int)(player->pos->y) >> 6) * map->map_width + \
		((int)(player->pos->x + COLLISION_OFFSET) >> 6)] == 1)
		return (1);
	if (map->map[((int)(player->pos->y) >> 6) * map->map_width + \
		((int)(player->pos->x - COLLISION_OFFSET) >> 6)] == 1)
		return (1);
	return (0);
}

void	move_player(t_player *player, t_map *map)
{
	if (player->keys->forward == 1)
	{
		player->pos->x += player->delta_x;
		if (check_out_map(player, map) == 1)
			player->pos->x -= player->delta_x;
		player->pos->y += player->delta_y;
		if (check_out_map(player, map) == 1)
			player->pos->y -= player->delta_y;
	}
	if (player->keys->backward == 1)
	{
		player->pos->x -= player->delta_x;
		if (check_out_map(player, map) == 1)
			player->pos->x += player->delta_x;
		player->pos->y -= player->delta_y;
		if (check_out_map(player, map) == 1)
			player->pos->y += player->delta_y;
	}
}
