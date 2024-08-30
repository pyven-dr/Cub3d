/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:30:26 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/24 02:06:28 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "mlx_funcs.h"

typedef struct s_color
{
	int		hexa;
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct s_object
{
	t_data	object_idle;
	t_data	object_use1;
	t_data	object_use2;
	t_data	object_use3;
	t_data	object_use_sec;
	int		frame_count;
	int		current_img;
}	t_object;

typedef struct s_map_data
{
	char		**map;
	t_object	object;
	t_data		menu;
	t_data		hood;
	t_data		map_img;
	t_data		north;
	t_data		south;
	t_data		east;
	t_data		west;
	t_color		floor;
	t_color		ceiling;
	int			map_height;
	int			map_width;
	int			number_player;
	int			pb;
}				t_map_data;

int		open_img(t_map_data *map_data, void *mlx_ptr);
int		open_xpm(void *mlx_ptr, t_data *nsew, char *path);
int		open_object_img(t_object *object, void *mlx_ptr);
void	free_img(void *mlx_ptr, t_map_data *map_data);

#endif