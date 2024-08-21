/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:38:09 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/21 20:08:28 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include "struct.h"

void	game_loop(t_game_data *game_data);
int		key_press(int key, t_keys *keys);
int		key_release(int key, t_keys *keys);
int		render_frame(t_map_data *map, t_player *player, t_mlx *mlx_data);
double	normalize_angle(double angle);
void	move_player(t_player *player, t_map_data *map);
void	rotate_player(t_player *player);

#endif
