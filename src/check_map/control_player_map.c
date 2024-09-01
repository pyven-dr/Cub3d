/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_player_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:12:25 by tcoze             #+#    #+#             */
/*   Updated: 2024/09/01 02:58:52 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "check_map.h"
#include "const_values.h"
#include "ft_printf.h"

static int	control_player(t_game_data *g_data, int y, int x)

{
	if (g_data->map_data.map[y][x] == 'N' || g_data->map_data.map[y][x] == 'S'
	|| g_data->map_data.map[y][x] == 'E' || g_data->map_data.map[y][x] == 'W')
	{
		if (g_data->map_data.map[y][x] == 'N')
			g_data->p.angle = 3 * M_PI_2;
		if (g_data->map_data.map[y][x] == 'S')
			g_data->p.angle = M_PI_2;
		if (g_data->map_data.map[y][x] == 'E')
			g_data->p.angle = 0;
		if (g_data->map_data.map[y][x] == 'W')
			g_data->p.angle = M_PI;
		g_data->p.pos.x = (x * 64) + 32;
		g_data->p.pos.y = (y * 64) + 32;
		g_data->p.fov = FOV * (M_PI / 180);
		g_data->p.delta_x = (int)(cos(g_data->p.angle) * 1.5);
		g_data->p.delta_y = (int)(sin(g_data->p.angle) * 1.5);
		g_data->p.plane_dist = (int)((PLANE_WIDTH / 2.0) \
			/ tan(g_data->p.fov / 2));
		return (1);
	}
	return (0);
}

static int	control_pos(t_game_data *g_data, int x, int y)
{
	if (x == 0 || y == 0)
		return (-1);
	if (y == g_data->map_data.pb - 1
		|| x == g_data->map_data.map_width - 1)
		return (-1);
	if ((g_data->map_data.map[y + 1][x] < '0'
		|| g_data->map_data.map[y + 1][x] > '2')
		&& control_player(g_data, y + 1, x) == 0)
		return (-1);
	if (y >= 1 && ((g_data->map_data.map[y - 1][x] < '0'
			|| g_data->map_data.map[y - 1][x] > '2')
		&& control_player(g_data, y - 1, x) == 0))
		return (-1);
	if ((g_data->map_data.map[y][x + 1] < '0'
		|| g_data->map_data.map[y][x + 1] > '2')
		&& control_player(g_data, y, x + 1) == 0)
		return (-1);
	if (x >= 1 && ((g_data->map_data.map[y][x - 1] < '0'
			|| g_data->map_data.map[y][x - 1] > '2')
		&& control_player(g_data, y, x - 1) == 0))
		return (-1);
	return (0);
}

int	control_map(t_game_data *g_data)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g_data->map_data.pb)
	{
		x = -1;
		while (g_data->map_data.map[y][++x])
		{
			if (g_data->map_data.map[y][x] == '0'
				|| g_data->map_data.map[y][x] == '2'
				|| control_player(g_data, y, x) == 1)
			{
				if (control_player(g_data, y, x) == 1)
					g_data->map_data.number_player++;
				if (control_pos(g_data, x, y) == -1)
					return (ft_printf(2, "Map is not closed\n"), -1);
			}
		}
		if (x > g_data->map_data.map_width)
			g_data->map_data.map_width = x;
	}
	if (g_data->map_data.number_player != 1)
		return (ft_printf(2, "Player number != 1\n"), -1);
	return (0);
}
