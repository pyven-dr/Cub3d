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
int		find_closest_wall(t_point ver_wall, t_point hor_wall, \
							double ray_angle, t_point player_pos);
int		ft_abs(int number);

#endif
