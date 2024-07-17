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

#include <stdio.h>

void controls(t_mlx *mlx_data, t_pressed_key *keys)
{
	mlx_hook(mlx_data->mlx_win, 17, 0, close_window, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, key_press, keys);
	mlx_hook(mlx_data->mlx_win, 3, 1L << 1, key_release, keys);
}

int	check_keys(t_pressed_key *keys)
{
	if (keys->forward == 1)
		printf("Forward\n");
	if (keys->backward == 1)
		printf("Backward\n");
	if (keys->left == 1)
		printf("Left\n");
	if (keys->right == 1)
		printf("Right\n");
	return (0);
}

void	game_loop(t_mlx *mlx_data, t_pressed_key *keys)
{
	controls(mlx_data, keys);
	mlx_loop_hook(mlx_data->mlx_ptr, check_keys, keys);
	mlx_loop(mlx_data->mlx_ptr);
}