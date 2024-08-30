/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:36:51 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 00:53:24 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "render.h"

void	draw_column(t_game_data *game_data, int j, int wall_h, t_inter *inter);
void	draw_pixel(t_game_data *game_data, int i, int j, t_inter *inter);
void	find_pos_tex_x(t_inter *inter, t_map_data *map_data);

#endif