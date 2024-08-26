/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 00:38:09 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 01:01:32 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_LOOP_H
# define GAME_LOOP_H

# include "player.h"
# include "map.h"

typedef struct s_game_data
{
	t_player	p;
	t_mlx		mlx_data;
	t_map_data	map_data;
}				t_game_data;

void	game_loop(t_game_data *game_data);
int		render_frame(t_game_data *game_data);
double	normalize_angle(double angle);
int		mouse_move(int x, int y, t_game_data *game_data);
void	init_game_data(t_game_data *game_data);
int		close_window(void *game_data);

#endif
