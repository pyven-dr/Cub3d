#ifndef CHECK_MAP_H
# define CHECK_MAP_H

#include "struct.h"

typedef struct s_true_map
{
	char	**map;
    t_data  north;
    t_data  south;
    t_data  east;
    t_data  west;
    int     floor;
    int     floor_r;
    int     floor_g;
    int     floor_b;
    int     ceiling;
    int     ceiling_r;
    int     ceiling_g;
    int     ceiling_b;
	int     map_height;
    int     map_width;
    int     number_player;
}	t_true_map;

int	pre_parsing(int argc, char **argv, t_true_map *true_map);

#endif