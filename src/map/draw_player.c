/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:29:05 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 04:29:05 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx_funcs.h"

void	draw_player(t_data *img, int square_size)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	start_x = (WIDTH >> 1) - (MAP_PLAYER_SIZE >> 1);
	start_y = (HEIGHT >> 1) - (MAP_PLAYER_SIZE >> 1);
	i = 0;
	while (i < MAP_PLAYER_SIZE)
	{
		j = 0;
		while (j < MAP_PLAYER_SIZE)
		{
			pixel_put(img, (start_x + square_size / 2) + i, \
					(start_y + square_size / 2) + j, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}
