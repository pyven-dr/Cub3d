/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:25:48 by tcoze             #+#    #+#             */
/*   Updated: 2024/03/18 00:21:53 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

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

static int	convert_color(int fc, char *line, t_true_map *true_map)
{
	while (*line < '0' || *line > '9')
		line++;
	//dprintf(2, "line : [%c]", *line);
	if (fc == 1)
	{
		true_map->floor_r = ft_atoi(line);
		//dprintf(2, "floor_r = %d\n", true_map->floor_r);
		if (true_map->floor_r < 0 || true_map->floor_r > 255)
			return (-1); // Erreur d'entree de couleur
		while (line && *line != ',')
			line++;
		true_map->floor_g = ft_atoi(++line);
		//dprintf(2, "floor_g = %d\n", true_map->floor_g);
		if (true_map->floor_g < 0 || true_map->floor_g > 255)
			return (-1); // Erreur d'entree de couleur
		while (line && *line != ',')
			line++;
		true_map->floor_b = ft_atoi(++line);
		//dprintf(2, "floor_b = %d\n", true_map->floor_b);
		if (true_map->floor_b < 0 || true_map->floor_b > 255)
			return (-1); // Erreur d'entree de couleur
		while (line && *line != ',')
			line++;
		true_map->floor = create_rgb(true_map->floor_r, true_map->floor_g, true_map->floor_b);
	}
	else
	{
		true_map->ceiling_r = ft_atoi(++line);
		if (true_map->ceiling_r < 0 || true_map->ceiling_r > 255)
			return (-1); // Erreur d'entree de couleur
		while (line && *line != ',')
			line++;
		true_map->ceiling_g = ft_atoi(++line);
		if (true_map->ceiling_g < 0 || true_map->ceiling_g > 255)
			return (-1); // Erreur d'entree de couleur
		while (line && *line != ',')
			line++;
		true_map->ceiling_b = ft_atoi(++line);
		if (true_map->ceiling_b < 0 || true_map->ceiling_b > 255)
			return (-1); // Erreur d'entree de couleur
		true_map->ceiling = create_rgb(true_map->ceiling_r, true_map->ceiling_g, true_map->ceiling_b);
	}
	return (0);
}

static void	end_line(char *line)
{
	while (line && *line != '\n')
		line++;
	*line = '\0';
}

static void	print_all(t_true_map *true_map)
{
	int i;

	i = 0;
	dprintf(2, "NO = [%s]\n", true_map->no);
	dprintf(2, "SO = [%s]\n", true_map->so);
	dprintf(2, "EA = [%s]\n", true_map->ea);
	dprintf(2, "WE = [%s]\n", true_map->we);
	dprintf(2, "F = [%x]\n", true_map->floor);
	dprintf(2, "C = [%x]\n", true_map->ceiling);
	dprintf(2, "----MAP----\n");
	while (i < true_map->map_height)
	{
		dprintf(2, "%s", true_map->map[i]);
		i++;
	}
	dprintf(2, "\n");
}

static int	check_textures_map(int fd, t_true_map *true_map) // Ajout des textures dans cub, a voir car pour le moment c'est gere si on met nimp dans le debut, genre aJSKJdbad NO ./path
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		i = 0;
		while(line[i] && line[i + 1] && line[i + 2])
		{
			if (line[i] == 'N' && line[i + 1] == 'O')
			{
				while (line[i] != '.')
					i++;
				true_map->no = ft_strdup(line + i);
				if (true_map->no == NULL)
					return (-1);
				end_line(true_map->no);
			}
			if (line[i] == 'S' && line[i + 1] == 'O')
			{
				while (line[i] != '.')
					i++;
				true_map->so = ft_strdup(line + i);
				if (true_map->so == NULL)
					return (-1);
				end_line(true_map->so);
			}
			if (line[i] == 'E' && line[i + 1] == 'A')
			{
				while (line[i] != '.')
					i++;
				true_map->ea = ft_strdup(line + i);
				if (true_map->ea == NULL)
					return (-1);
				end_line(true_map->ea);
			}
			if (line[i] == 'W' && line[i + 1] == 'E')
			{
				while (line[i] != '.')
					i++;
				true_map->we = ft_strdup(line + i);
				if (true_map->we == NULL)
					return (-1);
				end_line(true_map->we);
			}
			if (line[i] == 'F')
				if (convert_color(1, line + i, true_map) == -1)
					return (-1);
			if (line[i] == 'C')
				if (convert_color(2, line + i, true_map) == -1)
					return (-1);
			if (line[0] == ' ' | line[0] == '1')
			{
				true_map->map[j] = ft_strdup(line);
				if (!true_map->map[j])
					return (-1);
				j++;
				free(line);
				line = get_next_line(fd);
				if (!line)
					break ;
				if (line[0] != ' ' && line[0] != '1') // CHECK SI SAUT DE LIGNE PDT LA MAP
					return (-1);
			}
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	print_all(true_map);
	return (1);

}

static void	init_map(t_true_map *true_map)
{
	true_map->no = NULL;
	true_map->so = NULL;
	true_map->ea = NULL;
	true_map->we = NULL;
	true_map->ceiling = 0;
	true_map->ceiling_r = 0;
	true_map->ceiling_g = 0;
	true_map->ceiling_b = 0;
	true_map->floor = 0;
	true_map->floor_r = 0;
	true_map->floor_g = 0;
	true_map->floor_b = 0;
	true_map->map_height = 0;
	true_map->number_player = 0;
}

static int	pre_count_map(int fd, t_true_map *true_map)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		if (line[0] == ' ' | line[0] == '1')
			true_map->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		return (-1);
	true_map->map = malloc(sizeof(char *) * (true_map->map_height + 2));
	if (!true_map->map)
		return (-1);
	true_map->map[true_map->map_height + 1] = NULL;
	return (0);
}

static int	control_player(char **map, int y, int x) // CHECK SI PLUSIEURS POSITIONS DE DEPART PLAYER
{
	if (map[y][x] == 'N' || map[y][x] == 'S')
		return (1);
	if (map[y][x] == 'E' || map[y][x] == 'W')
		return (1);
	return (0);
}

static int	control_map(t_true_map *true_map)
{
	int	y;
	int	x;

	y = 0;
	while (y < true_map->map_height)
	{
		x = 0;
		while (true_map->map[y][x])
		{
			if (true_map->map[y][x] == '0' || control_player(true_map->map, y, x) == 1)
			{
				if (control_player(true_map->map, y, x) == 1)
					true_map->number_player++;
				if (true_map->map[y + 1][x] != '0' && true_map->map[y + 1][x] != '1' && control_player(true_map->map, y + 1, x) == 0)
					return (-1);
				if (y >= 1 && (true_map->map[y - 1][x] != '0' && true_map->map[y - 1][x] != '1' && control_player(true_map->map, y - 1, x) == 0))
					return (-1);
				if (true_map->map[y][x + 1] != '0' && true_map->map[y][x + 1] != '1' && control_player(true_map->map, y, x + 1) == 0)
					return (-1);
				if (x >= 1 && (true_map->map[y][x - 1] != '0' && true_map->map[y][x - 1] != '1' && control_player(true_map->map, y, x - 1) == 0))
					return (-1);
			}
			x++;
		}
		y++;
	}
	if (true_map->number_player > 1)
		return (-1);
	return (0);
}

int	pre_parsing(int argc, char **argv, t_true_map *true_map)
{
	int		fd;
	int		i;

	i = 0;
	if (argc != 2)
		return (-1);
	init_map(true_map);
	if (check_cub(argv[1]) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (pre_count_map(fd, true_map) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	if (check_textures_map(fd, true_map) == -1)
		return (-1);
	if (close(fd) == -1)
		return (-1);
	if (control_map(true_map) == -1)
	{
		dprintf(2, "map error");
		return (-1);
	}
	return (0);
}
