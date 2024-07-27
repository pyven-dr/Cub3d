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

t_point	find_v_wall(double ray_angle, t_player *player, t_map *map);
t_point	find_h_wall(double ray_angle, t_player *player, t_map *map);
double	find_closest_wall(t_point ver, t_point hor, t_point *p_pos);
void	trace_column(double dist, int col_numb, t_mlx *mlx_data, int pln_dist);

#endif
