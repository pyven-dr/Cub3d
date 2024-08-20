#ifndef CHECK_MAP_H
# define CHECK_MAP_H

typedef struct s_true_map
{
	char	**map;
    char    *no;
    char    *so;
    char    *ea;
    char    *we;
    int     floor;
    int     floor_r;
    int     floor_g;
    int     floor_b;
    int     ceiling;
    int     ceiling_r;
    int     ceiling_g;
    int     ceiling_b;
	int     map_height;
    int     number_player;
}	t_true_map;

int	pre_parsing(int argc, char **argv, t_true_map *true_map);

#endif