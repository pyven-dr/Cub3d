/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:49:38 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/25 22:52:53 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "const_values.h"
#include "game_loop.h"

void	rotate_player(t_player *player)
{
	player->delta_x = cos(player->angle) * MOVE_SPEED;
	player->delta_y = sin(player->angle) * MOVE_SPEED;
	if (player->keys.look_right == 1)
		player->angle = normalize_angle(player->angle + ROTATION_SPEED);
	if (player->keys.look_left == 1)
		player->angle = normalize_angle(player->angle - ROTATION_SPEED);
	if (player->keys.up == 1)
		player->vert_offset += HOR_ROTATION_SPEED;
	if (player->keys.down == 1)
		player->vert_offset -= HOR_ROTATION_SPEED;
}
