/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:37:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/24 05:34:13 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "mlx.h"
#include "mlx_funcs.h"
#include "const_values.h"
#include "math.h"

int	mouse_press(int x, int y, t_game_data *game_data)
{
	#include <stdio.h>
	
	int	new_x;
	
	(void)y;
	//printf("x : [%d] | y : [%d]  %d %d amgle before %lf\n", x, y, game_data->p.keys.mouse.x, game_data->p.keys.mouse.y, game_data->p.angle);
	new_x = x - game_data->p.keys.mouse.x;
	game_data->p.angle = game_data->p.angle + (new_x / 2000.);
	game_data->p.angle = normalize_angle(game_data->p.angle);
	game_data->p.delta_x = cos(game_data->p.angle) * MOVE_SPEED;
	game_data->p.delta_y = sin(game_data->p.angle) * MOVE_SPEED;
	mlx_mouse_move(game_data->mlx_data.mlx_ptr, game_data->mlx_data.mlx_win, WIDTH / 2, HEIGHT / 2);
	game_data->p.keys.mouse.x = WIDTH / 2;
	game_data->p.keys.mouse.y = HEIGHT / 2;
	return (0);
}

void	controls(t_mlx *mlx_data, t_player *player, t_game_data	*game_data)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, close_window, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, key_press, &player->keys);
	mlx_hook(mlx_data->mlx_win, 6, 1L << 6, mouse_press, game_data);
	mlx_hook(mlx_data->mlx_win, 3, 1L << 1, key_release, &player->keys);
}

int	render(t_game_data	*game_data)
{
	if (game_data->p.keys.esc == 1)
		close_window(&game_data->mlx_data);
	move_player(&game_data->p, &game_data->map_data);
	rotate_player(&game_data->p);
	render_frame(game_data);
	mlx_put_image_to_window(game_data->mlx_data.mlx_ptr, \
	game_data->mlx_data.mlx_win, game_data->mlx_data.img_data.img, 0, 0);
	return (0);
}

void	game_loop(t_game_data *game_data)
{
	controls(&game_data->mlx_data, &game_data->p, game_data);
	mlx_loop_hook(game_data->mlx_data.mlx_ptr, render, game_data);
	mlx_loop(game_data->mlx_data.mlx_ptr);
}
