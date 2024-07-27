/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:37:14 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/13 00:37:14 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_loop.h"
#include "mlx.h"
#include "mlx_funcs.h"

void	controls(t_mlx *mlx_data, t_keys *keys)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, close_window, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, key_press, keys);
	mlx_hook(mlx_data->mlx_win, 3, 1L << 1, key_release, keys);
}

int	render(t_game_data	*game_data)
{
	move_player(game_data->player, game_data->map);
	rotate_player(game_data->player);
	render_frame(game_data->map, game_data->player, game_data->mlx_data);
	mlx_put_image_to_window(game_data->mlx_data->mlx_ptr, \
	game_data->mlx_data->mlx_win, game_data->mlx_data->img_data->img, 0, 0);
	return (0);
}

void	game_loop(t_game_data *game_data)
{
	controls(game_data->mlx_data, game_data->player->keys);
	mlx_loop_hook(game_data->mlx_data->mlx_ptr, render, game_data);
	mlx_loop(game_data->mlx_data->mlx_ptr);
}
