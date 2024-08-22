/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:30:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/23 01:30:26 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "mlx_funcs.h"

typedef struct s_color
{
	int     hexa;
	int     r;
	int     g;
	int     b;
}			t_color;

typedef struct s_map_data
{
	char	**map;
	t_data  north;
	t_data  south;
	t_data  east;
	t_data  west;
	t_color	floor;
	t_color	ceiling;
	int     map_height;
	int     map_width;
	int     number_player;
}	t_map_data;


#endif
