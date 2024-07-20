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

#include "mlx.h"
#include "struct.h"
#include "mlx_funcs.h"
#include "game_loop.h"
#include <stdlib.h>
#include <math.h>

#include <stdio.h>

void controls(t_mlx *mlx_data, t_keys *keys)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, close_window, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, key_press, keys);
	mlx_hook(mlx_data->mlx_win, 3, 1L << 1, key_release, keys);
}

int	check_out_map(t_player *player, t_map *map)
{
	if (map->map[((int)(player->pos->y) >> 6) * map->map_width + ((int)(player->pos->x) >> 6)] == 1)
		return (1);
	return (0);
}

void	move_player(t_player *player, t_map *map)
{
	if (player->keys->forward == 1)
	{
		player->pos->x += player->delta_x;
		player->pos->y += player->delta_y;
		if (check_out_map(player, map) == 1)
		{
			player->pos->x -= player->delta_x;
			player->pos->y -= player->delta_y;
		}
	}
	if (player->keys->backward == 1)
	{
		player->pos->x -= player->delta_x;
		player->pos->y -= player->delta_y;
		if (check_out_map(player, map) == 1)
		{
			player->pos->x += player->delta_x;
			player->pos->y += player->delta_y;
		}
	}
}

void	rotate_player(t_player *player)
{
	if (player->keys->right == 1)
	{
		player->angle = normalize_angle(player->angle + 0.01);
		player->delta_x = (int)(cos(player->angle) * 1.5);
		player->delta_y = (int)(sin(player->angle) * 1.5);
	}
	if (player->keys->left == 1)
	{
		player->angle = normalize_angle(player->angle - 0.01);
		player->delta_x = (int)(cos(player->angle) * 1.5);
		player->delta_y = (int)(sin(player->angle) * 1.5);
	}
}

int	render(t_game_data	*game_data)
{
	move_player(game_data->player, game_data->map);
	rotate_player(game_data->player);
	//printf("%f %f %f\n", game_data->player->pos->x, game_data->player->pos->y, game_data->player->angle);
	if (game_data->mlx_data->img_data->img != NULL)
		mlx_destroy_image(game_data->mlx_data->mlx_ptr,game_data->mlx_data->img_data->img);
	if (new_image(game_data->mlx_data) == 1)
		return (1);
	render_frame(game_data->map, game_data->player, game_data->mlx_data);
	mlx_put_image_to_window(game_data->mlx_data->mlx_ptr, game_data->mlx_data->mlx_win, game_data->mlx_data->img_data->img, 0, 0);
	return (0);
}

void	game_loop(t_game_data *game_data)
{
	controls(game_data->mlx_data, game_data->player->keys);
	mlx_loop_hook(game_data->mlx_data->mlx_ptr, render, game_data);
	//render(game_data);
	mlx_loop(game_data->mlx_data->mlx_ptr);
}