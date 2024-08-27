/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_textures_or_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:45:39 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/27 07:01:23 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

static int	is_color(char *line, char fc, t_color *color)
{
	if (line[0] == fc)
	{
		if (convert_color(line + 1, color) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	is_textures(char *line, char a, char b, char **path)
{
	if (line[0] == a && line[1] == b)
	{
		if (fill_path(line, path) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

static int	check_colors(char *line, t_map_data *map_data)
{
	int	return_value;

	return_value = is_color(line, 'F', &map_data->floor);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = is_color(line, 'C', &map_data->ceiling);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return (0);
}

static int	check_textures(char *line, t_map_data *map_data)
{
	int	return_value;

	return_value = is_textures(line, 'N', 'O', &map_data->north.path);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = is_textures(line, 'S', 'O', &map_data->south.path);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = is_textures(line, 'E', 'A', &map_data->east.path);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = is_textures(line, 'W', 'E', &map_data->west.path);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return (0);
}

int	check_textures_colors(char *line, t_map_data *map_data)
{
	int	return_value;

	return_value = check_textures(line, map_data);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = check_colors(line, map_data);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return (0);
}
