/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:36:51 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/25 21:46:27 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

int		get_pixel_color(const t_data *img_data, int x, int y);
int		get_texture_color(const t_data *tex_data, t_inter inter, double pos_tex);
void	draw_column(t_game_data *game_data, int j, int wall_h, t_inter inter);
void	draw_pixel(t_game_data *game_data, int i, int j, t_inter inter);
#endif