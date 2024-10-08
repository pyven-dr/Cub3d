/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:48:18 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 00:55:30 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "render.h"

static int	is_wall(double x, double y, t_map_data *map_data)
{
	char	point;

	point = get_map_point(x, y, map_data);
	if (point == '1' || point == '2')
		return (1);
	return (0);
}

static int	check_out_map(t_player *player, t_map_data *map)
{
	if (is_wall(player->pos.x, player->pos.y + COLLISION_OFFSET, \
		map) == 1)
		return (1);
	if (is_wall(player->pos.x, player->pos.y - COLLISION_OFFSET, \
		map) == 1)
		return (1);
	if (is_wall(player->pos.x + COLLISION_OFFSET, player->pos.y, \
		map) == 1)
		return (1);
	if (is_wall(player->pos.x - COLLISION_OFFSET, player->pos.y, \
		map) == 1)
		return (1);
	return (0);
}

static void	move_player_f_b(t_player *player, t_map_data *map)
{
	if (player->keys.forward == 1)
	{
		player->pos.x += player->delta_x;
		if (check_out_map(player, map) == 1)
			player->pos.x -= player->delta_x;
		player->pos.y += player->delta_y;
		if (check_out_map(player, map) == 1)
			player->pos.y -= player->delta_y;
	}
	if (player->keys.backward == 1)
	{
		player->pos.x -= player->delta_x;
		if (check_out_map(player, map) == 1)
			player->pos.x += player->delta_x;
		player->pos.y -= player->delta_y;
		if (check_out_map(player, map) == 1)
			player->pos.y += player->delta_y;
	}
}

static void	move_player_l_r(t_player *player, t_map_data *map)
{
	if (player->keys.right == 1)
	{
		player->pos.x -= player->delta_y;
		if (check_out_map(player, map) == 1)
			player->pos.x += player->delta_y;
		player->pos.y += player->delta_x;
		if (check_out_map(player, map) == 1)
			player->pos.y -= player->delta_x;
	}
	if (player->keys.left == 1)
	{
		player->pos.x += player->delta_y;
		if (check_out_map(player, map) == 1)
			player->pos.x -= player->delta_y;
		player->pos.y -= player->delta_x;
		if (check_out_map(player, map) == 1)
			player->pos.y += player->delta_x;
	}
}

void	move_player(t_player *player, t_map_data *map)
{
	move_player_f_b(player, map);
	move_player_l_r(player, map);
}
