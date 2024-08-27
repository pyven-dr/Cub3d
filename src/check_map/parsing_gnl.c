/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:17:08 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/27 06:49:52 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "ft_printf.h"

static char	*get_text_colors(int fd, t_map_data *map_data)
{
	char	*line;
	int		return_value;

	line = get_next_line(fd);
	if (line == NULL)
		return (NULL);
	while (line)
	{
		if (line[0] != '\n')
		{
			if (line[0] && line[1])
			{
				return_value = check_textures_colors(line, map_data);
				if (return_value == -1)
					return (free(line), NULL);
				if (return_value == 0)
					return (line);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

static int	control_text_color(t_map_data *map_data, char *line)
{
	if (line == NULL)
	{
		ft_printf(2, "Error textures or color\n");
		return (-1);
	}
	if (map_data->east.path == NULL || map_data->north.path == NULL
		|| map_data->west.path == NULL || map_data->south.path == NULL
		|| map_data->ceiling.hexa == -1 || map_data->floor.hexa == -1)
	{
		ft_printf(2, "Color or Textures missing\n");
		return (-1);
	}
	return (0);
}

static int	check_line_map(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != 'N' && map[i] != 'S'
			&& map[i] != 'E' && map[i] != 'W' && map[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}

static int	control_map_gnl(int fd, t_map_data *map_data, char *line)
{
	int	j;

	j = 0;
	while (line && (line[0] == ' ' || line[0] == '1'))
	{
		map_data->map[j] = ft_strdup(line);
		if (!map_data->map[j])
			return (free(line), -1);
		map_data->pb++;
		if (check_line_map(map_data->map[j]) == -1)
		{
			free(line);
			return (-1);
		}
		j++;
		free(line);
		line = get_next_line(fd);
	}
	if (line == NULL)
		return (0);
	free(line);
	return (-1);
}

int	parsing_gnl(int fd, t_map_data *map_data)
{
	char	*line;
	int		j;

	j = 0;
	line = get_text_colors(fd, map_data);
	if (control_text_color(map_data, line) == -1)
		return (-1);
	if (control_map_gnl(fd, map_data, line) == -1)
		return (-1);
	return (1);
}
