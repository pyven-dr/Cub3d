/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 00:36:57 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 00:48:15 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"
#include "mlx.h"
#include <math.h>

int	mouse_move(int x, t_game_data *g_data)
{
	int	new_x;

	if (g_data->p.keys.alt == 1)
	{
		mlx_mouse_hide(g_data->mlx_data.mlx_ptr, g_data->mlx_data.mlx_win);
		new_x = x - g_data->p.keys.mouse.x;
		g_data->p.angle = g_data->p.angle + (new_x / 2000.);
		g_data->p.angle = normalize_angle(g_data->p.angle);
		g_data->p.delta_x = cos(g_data->p.angle) * MOVE_SPEED;
		g_data->p.delta_y = sin(g_data->p.angle) * MOVE_SPEED;
		if (g_data->p.keys.mouse.is_recentering == 1)
		{
			g_data->p.keys.mouse.is_recentering = 0;
			return (0);
		}
		else
		{
			g_data->p.keys.mouse.is_recentering = 1;
			mlx_mouse_move(g_data->mlx_data.mlx_ptr, \
			g_data->mlx_data.mlx_win, WIDTH / 2, HEIGHT / 2);
		}
	}
	else
		mlx_mouse_show(g_data->mlx_data.mlx_ptr, g_data->mlx_data.mlx_win);
	return (0);
}
