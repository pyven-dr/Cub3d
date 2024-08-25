/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 04:39:46 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/24 04:39:46 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "const_values.h"

void	player_size(t_player *player)
{
	if (player->keys.fly == 1 && player->player_size >= 0.2)
		player->player_size -= FLY_SPEED;
	if (player->keys.crouch == 1)
	{
		if (player->player_size < 1)
			player->player_size += FLY_SPEED;
		else
			player->player_size = 1.5;
	}
	if (player->player_size == 1.5 && player->keys.crouch == 0)
		player->player_size = 1;
}
