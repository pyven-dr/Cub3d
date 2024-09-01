/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 00:51:11 by tcoze             #+#    #+#             */
/*   Updated: 2024/09/01 04:09:33 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include "game_loop.h"

int		pre_parsing(char **argv, t_game_data *game_data);
void	init_map(t_map_data *map_data);
int		control_map(t_game_data *game_data);
int		check_cub(char *file);
int		is_color(char *line, char fc, t_color *color);
int		parsing_gnl(int fd, t_map_data *map_data);
int		fill_nsew_struct(t_game_data *game_data);
int		check_textures_colors(char *line, t_map_data *map_data);
int		check_textures_no_so_ea(char *line, t_map_data *map_data);
int		check_textures_we_do(char *line, t_map_data *map_data);
int		fill_path(char *line, char **path);
void	free_parsing(t_game_data *game_data);
#endif