/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:25:48 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/24 01:20:34 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"
#include "fcntl.h"

static int	pre_count_map(int fd, t_map_data *map_data)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (line[0] == ' ' | line[0] == '1')
			map_data->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (free(line), -1);
	map_data->map = malloc(sizeof(char *) * (map_data->map_height + 2));
	if (!map_data->map)
		return (free(line), -1);
	map_data->map[map_data->map_height + 1] = NULL;
	return (0);
}

int	pre_parsing(int argc, char **argv, t_game_data *game_data)
{
	int		fd;
	int		i;

	i = 0;
	game_data->map_data.north.img = NULL;
	game_data->map_data.south.img = NULL;
	game_data->map_data.east.img = NULL;
	game_data->map_data.west.img = NULL;
	
	if (argc != 2)
		return (-1);
	init_map(&game_data->map_data);
	if (check_cub(argv[1]) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (pre_count_map(fd, &game_data->map_data) == -1)
		return (free_parsing(game_data), -1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (free(game_data->map_data.map), -1);
	if (parsing_gnl(fd, &game_data->map_data) == -1)
		return (free_parsing(game_data), close(fd), -1);
	if (close(fd) == -1)
		return (free_parsing(game_data), -1);
	if (control_map(game_data) == -1)
	{
		//dprintf(2, "map error");
		return (free_parsing(game_data), -1);
	}
	if (fill_nsew_struct(game_data) == -1)
		return (free_parsing(game_data), -1);
	return (0);
}
