/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:25:48 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/22 18:32:01 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "mlx.h"
#include "const_values.h"

static int	check_cub(char *file)	// a verifier si on peut faire des ..cub ou quoi en nom de map
{
	size_t	len;

	if (!file || ft_strlen(file) < 5)
		return (-1);
	len = ft_strlen(file);
	if (file[len - 1] != 'b')
		return (-1);
	if (file[len - 2] != 'u')
		return (-1);
	if (file[len - 3] != 'c')
		return (-1);
	if (file[len - 4] != '.')
		return (-1);
	return (0);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	convert_color(char *line, t_color *color)
{
	if (color->hexa != 0)
		return (-1);
	while (*line < '0' || *line > '9')
		line++;
	//dprintf(2, "line : [%c]", *line);
	color->r = ft_atoi(line);
	//dprintf(2, "color->r = %d\n", color->r);
	if (color->r < 0 || color->r > 255)
		return (-1); // Erreur d'entree de couleur
	while (line && *line != ',')
		line++;
	color->g = ft_atoi(++line);
	//dprintf(2, "color->g = %d\n", color->g);
	if (color->g < 0 || color->g > 255)
		return (-1); // Erreur d'entree de couleur
	while (line && *line != ',')
		line++;
	color->b = ft_atoi(++line);
	//dprintf(2, "color->b = %d\n", color->b);
	if (color->b < 0 || color->b > 255)
		return (-1); // Erreur d'entree de couleur
	while (*line >= '0' && *line <= '9')
		line++;
	if (*line != '\n' && *line != '\0')
		return (-1);
	color->hexa = create_rgb(color->r, color->g, color->b);
	return (0);
}

static void	end_line(char *line)
{
	while (line && *line != '\n')
		line++;
	*line = '\0';
}

static void	print_all(t_map_data *map_data)
{
	int i;

	i = 0;
	dprintf(2, "NO = [%s]\n", map_data->north.path);
	dprintf(2, "SO = [%s]\n", map_data->south.path);
	dprintf(2, "EA = [%s]\n", map_data->east.path);
	dprintf(2, "WE = [%s]\n", map_data->west.path);
	dprintf(2, "F = [%x]\n", map_data->floor.hexa);
	dprintf(2, "C = [%x]\n", map_data->ceiling.hexa);
	dprintf(2, "MAP_DATA HEIGHT = [%d]\n", map_data->map_height);
	dprintf(2, "MAP_DATA WIDTH = [%d]\n", map_data->map_width);
	
	dprintf(2, "----MAP_data----\n");
	while (i < map_data->map_height)
	{
		dprintf(2, "%s", map_data->map[i]);
		i++;
	}
	dprintf(2, "\n");
}

static int	fill_path(char *line, char **path)
{
	int i;

	i = 2;
	if (*path != NULL) // JE SAIS PAS PQ IL PLANTE SI JE METS LA LIGNE POUR CONTROLER SI Y'A DEJA UN PATH
		return (-1);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i + 1] && line[i] != '.' && line[i + 1] != '/')
		return (-1);
	*path = ft_strdup(line + i);
	if (path == NULL)
		return (-1);
	end_line(*path);
	return (0);
}

static int	file_to_struct(t_game_data *game_data, t_data *nsew)
{
	nsew->img = mlx_xpm_file_to_image(game_data->mlx_data.mlx_ptr, nsew->path, &nsew->width, &nsew->height);
	if (nsew->img == NULL)
		return (-1);
    nsew->addr = mlx_get_data_addr(nsew->img, &nsew->bits_per_pixel, &nsew->line_length, &nsew->endian);
	return (0);
}

static int	check_textures_map(int fd, t_map_data *map_data)
{
	char	*line;
	int		j;

	j = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		if(line[0] && line[1])
		{
//			dprintf(2, "pete avant fill text\n");
			if (line[0] == 'N' && line[1] == 'O')
			{
				if (fill_path(line, &map_data->north.path) == -1)
					return (-1);
			}
//			dprintf(2, "pete apres no\n");
			else if (line[0] == 'S' && line[1] == 'O')
			{
				if (fill_path(line, &map_data->south.path) == -1)
					return (-1);
			}
			else if (line[0] == 'E' && line[1] == 'A')
			{
				if (fill_path(line, &map_data->east.path) == -1)
					return (-1);
			}
			else if (line[0] == 'W' && line[1] == 'E')
			{
				if (fill_path(line, &map_data->west.path) == -1)
					return (-1);
			}
//			dprintf(2, "pete apres fill text\n");
			else if (line[0] == 'F')
			{
				if (convert_color(line + 1, &map_data->floor) == -1)
					return (-1);
			}
			else if (line[0] == 'C')
			{
				if (convert_color(line + 1, &map_data->ceiling) == -1)
			 		return (-1);
			}
			else if (line[0] == ' ' || line[0] == '1')
			{
				while (line[0] == ' ' || line[0] == '1')
				{
					if (map_data->east.path == NULL || map_data->north.path == NULL || map_data->west.path == NULL || map_data->south.path == NULL)
						return (-1);
					map_data->map[j] = ft_strdup(line);
					if (!map_data->map[j])
						return (-1);
					j++;
					free(line);
					line = get_next_line(fd);
					if (!line)
						break ;
					if (line[0] != ' ' && line[0] != '1') // CHECK SI SAUT DE LIGNE PDT LA MAP
						return (-1);
				}
			}
			else
				return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

static void	init_map(t_map_data *map_data)
{
	map_data->north.path = NULL;
	map_data->south.path = NULL;
	map_data->east.path = NULL;
	map_data->west.path = NULL;
	map_data->ceiling.hexa = 0;
	map_data->ceiling.r = 0;
	map_data->ceiling.g = 0;
	map_data->ceiling.b = 0;
	map_data->floor.hexa = 0;
	map_data->floor.r = 0;
	map_data->floor.g = 0;
	map_data->floor.b = 0;
	map_data->map_height = 0;
	map_data->map_width = 0;
	map_data->number_player = 0;
}

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
		return (-1);
	map_data->map[map_data->map_height + 1] = NULL;
	return (0);
}
static int	control_player(t_game_data *game_data, int y, int x)

{
	if (game_data->map_data.map[y][x] == 'N' || game_data->map_data.map[y][x] == 'S' ||
		game_data->map_data.map[y][x] == 'E' || game_data->map_data.map[y][x] == 'W')
	{
		if (game_data->map_data.map[y][x] == 'N')
			game_data->player.angle = (M_PI) / 2;
		if (game_data->map_data.map[y][x] == 'S')
			game_data->player.angle = (3 * M_PI) / 2;
		if (game_data->map_data.map[y][x] == 'E')
			game_data->player.angle = (M_PI);		
		if (game_data->map_data.map[y][x] == 'W')
			game_data->player.angle = (0);
		game_data->player.pos.x = x * 64;
		game_data->player.pos.y = y * 64;
		game_data->player.fov = FOV * (M_PI / 180);
		game_data->player.delta_x = (int)(cos(game_data->player.angle) * 1.5);
		game_data->player.delta_y = (int)(sin(game_data->player.angle) * 1.5);
		game_data->player.plane_dist = (int)((PLANE_WIDTH / 2.0) / tan(game_data->player.fov / 2));
		return (1);
	}
	return (0);
}

static int	control_map(t_game_data *game_data)
{
	int	y;
	int	x;

	y = 0;
	while (y < game_data->map_data.map_height)
	{
		x = 0;
		while (game_data->map_data.map[y][x])
		{
			if (game_data->map_data.map[y][x] == '0' || control_player(game_data, y, x) == 1)
			{
				if (control_player(game_data, y, x) == 1)
					game_data->map_data.number_player++;
				if (game_data->map_data.map[y + 1][x] != '0' && game_data->map_data.map[y + 1][x] != '1' && control_player(game_data, y + 1, x) == 0)
					return (-1);
				if (y >= 1 && (game_data->map_data.map[y - 1][x] != '0' && game_data->map_data.map[y - 1][x] != '1' && control_player(game_data, y - 1, x) == 0))
					return (-1);
				if (game_data->map_data.map[y][x + 1] != '0' && game_data->map_data.map[y][x + 1] != '1' && control_player(game_data, y, x + 1) == 0)
					return (-1);
				if (x >= 1 && (game_data->map_data.map[y][x - 1] != '0' && game_data->map_data.map[y][x - 1] != '1' && control_player(game_data, y, x - 1) == 0))
					return (-1);
			}
			x++;
		}
		if (x > game_data->map_data.map_width)
			game_data->map_data.map_width = x;
		y++;
	}
	if (game_data->map_data.number_player != 1)
		return (-1);
	return (0);
}

static int	fill_nsew_struct(t_game_data *game_data)
{
	if (file_to_struct(game_data, &game_data->map_data.north) == -1)
		return (-1);
	if (file_to_struct(game_data, &game_data->map_data.south) == -1)
		return (-1);
	if (file_to_struct(game_data, &game_data->map_data.east) == -1)
		return (-1);
	if (file_to_struct(game_data, &game_data->map_data.west) == -1)
		return (-1);
	return (0);
}

int	pre_parsing(int argc, char **argv, t_game_data *game_data)
{
	int		fd;
	int		i;

	i = 0;
	if (argc != 2)
		return (-1);
	init_map(&game_data->map_data);
	if (check_cub(argv[1]) == -1)
		return (-1);
	dprintf(2, "CHECK CUB OK\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (pre_count_map(fd, &game_data->map_data) == -1)
		return (-1);
	dprintf(2, "CHECK PRE_COUNT OK\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (free(game_data->map_data.map), -1);
	if (check_textures_map(fd, &game_data->map_data) == -1)
		return (-1);
	dprintf(2, "CHECK TEXTURES OK\n");
	if (close(fd) == -1)
		return (-1);
	if (control_map(game_data) == -1)
	{
		dprintf(2, "map error");
		return (-1);
	}
	dprintf(2, "PLAYER X : [%f]\n", game_data->player.pos.x);
	dprintf(2, "PLAYER Y : [%f]\n", game_data->player.pos.y);
	dprintf(2, "PLAYER ANGLE : [%f]\n", game_data->player.angle);
	print_all(&game_data->map_data);
	if (fill_nsew_struct(game_data) == -1)
		return (-1);
	return (0);
}
