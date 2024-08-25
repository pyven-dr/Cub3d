/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:30:35 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/26 00:42:27 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "const_values.h"

void	init_game_data(t_game_data *game_data)
{
	game_data->p.keys.backward = 0;
	game_data->p.keys.forward = 0;
	game_data->p.keys.look_left = 0;
	game_data->p.keys.look_right = 0;
	game_data->p.keys.esc = 0;
	game_data->p.keys.up = 0;
	game_data->p.keys.down = 0;
	game_data->p.keys.alt = 0;
	game_data->p.vert_offset = 1;
	game_data->p.player_size = 1;
	game_data->p.keys.mouse.is_recentering = 0;
	game_data->p.keys.mouse.x = WIDTH / 2;
	game_data->p.keys.mouse.y = HEIGHT / 2;
}
