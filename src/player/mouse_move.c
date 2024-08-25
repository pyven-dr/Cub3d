/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:36:57 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/25 22:52:57 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"
#include "mlx.h"
#include <math.h>

int	mouse_move(int x, int y, t_game_data *game_data)
{
	if (game_data->p.keys.alt == 1)
	{
		mlx_mouse_hide(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.mlx_win);
		game_data->p.angle += ((x - game_data->p.keys.mouse.x) / 10.0) \
								* ROTATION_SPEED;
		game_data->p.angle = normalize_angle(game_data->p.angle);
		game_data->p.vert_offset -= (y - game_data->p.keys.mouse.y) \
									/ 10.0 * HOR_ROTATION_SPEED;
		game_data->p.delta_x = cos(game_data->p.angle) * MOVE_SPEED;
		game_data->p.delta_y = sin(game_data->p.angle) * MOVE_SPEED;
		if (game_data->p.keys.mouse.is_recentering == 1)
			game_data->p.keys.mouse.is_recentering = 0;
		else
		{
			game_data->p.keys.mouse.is_recentering = 1;
			mlx_mouse_move(game_data->mlx_data.mlx_ptr, \
			game_data->mlx_data.mlx_win, WIDTH / 2, HEIGHT / 2);
		}
	}
	else
		mlx_mouse_show(game_data->mlx_data.mlx_ptr, \
				game_data->mlx_data.mlx_win);
	return (0);
}
