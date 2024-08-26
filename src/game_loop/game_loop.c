/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:37:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/25 22:00:43 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "mlx.h"
#include "mlx_funcs.h"

void	controls(t_mlx *mlx_data, t_game_data *game_data)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, close_window, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, key_press, &game_data->p.keys);
	mlx_hook(mlx_data->mlx_win, 6, 1L << 6, mouse_move, game_data);
	mlx_hook(mlx_data->mlx_win, 3, 1L << 1, key_release, &game_data->p.keys);
}

int	render(t_game_data	*game_data)
{
	if (game_data->p.keys.esc == 1)
		close_window(game_data);
	if (game_data->p.keys.menu == 0)
	{
		move_player(&game_data->p, &game_data->map_data);
		player_size(&game_data->p);
		rotate_player(&game_data->p);
		render_frame(game_data);
		if (game_data->p.keys.hood == 1)
			display_img(&game_data->map_data.hood, \
			&game_data->mlx_data.img_data);
	}
	else
		display_img(&game_data->map_data.menu, &game_data->mlx_data.img_data);
	mlx_put_image_to_window(game_data->mlx_data.mlx_ptr, \
	game_data->mlx_data.mlx_win, game_data->mlx_data.img_data.img, 0, 0);
	return (0);
}

void	game_loop(t_game_data *game_data)
{
	controls(&game_data->mlx_data, game_data);
	mlx_loop_hook(game_data->mlx_data.mlx_ptr, render, game_data);
	mlx_loop(game_data->mlx_data.mlx_ptr);
}
