/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:49:38 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/21 10:49:38 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include <math.h>

void	rotate_player(t_player *player)
{
	if (player->keys->right == 1)
		player->angle = normalize_angle(player->angle + 0.01);
	if (player->keys->left == 1)
		player->angle = normalize_angle(player->angle - 0.01);
	player->delta_x = cos(player->angle) * 2;
	player->delta_y = sin(player->angle) * 2;
}
