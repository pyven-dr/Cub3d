#ifndef CHECK_MAP_H
# define CHECK_MAP_H

#include "game_loop.h"

int	    pre_parsing(int argc, char **argv, t_game_data *game_data);
void	init_map(t_map_data *map_data);
int     control_map(t_game_data *game_data);
int     check_cub(char *file);
int     convert_color(char *line, t_color *color);
int     parsing_gnl(int fd, t_map_data *map_data);
int     fill_nsew_struct(t_game_data *game_data);
int     check_textures_colors(char *line, t_map_data *map_data);
int     fill_path(char *line, char **path);
void	free_parsing(t_game_data *game_data);
#endif