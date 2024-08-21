/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:46:56 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/18 00:46:56 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "struct.h"

t_point	find_v_wall(double ray_angle, t_player *player, t_map_data *map);
t_point	find_h_wall(double ray_angle, t_player *player, t_map_data *map);
t_inter	find_closest_wall(double angle, t_player *player, t_map_data *map);
void	trace_column(t_inter inter, int col_numb, t_mlx *mlx_data, \
					int pln_dist);
void	find_orientation_ver(t_inter *inter, double ray_angle);
void	find_orientation_hor(t_inter *inter, double ray_angle);
void	draw_column(t_mlx *mlx_data, int j, int wall_h, t_inter inter);
t_inter	find_clos_inter(t_inter ver, t_inter hor, t_map_data *map, double angle);
char	get_map_point(double x, double y, t_map_data *map);

#endif
