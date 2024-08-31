/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 00:53:20 by tcoze             #+#    #+#             */
/*   Updated: 2024/09/01 00:58:59 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

static int	is_textures(char *line, char a, char b, char **path)
{
	while (*line == ' ')
		line++;
	if (*line == a && *(line + 1) == b)
	{
		if (fill_path(line, path) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

int	check_textures_NO_SO_EA(char *line, t_map_data *map_data)
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
	return (0);
}
int	check_textures_WE_DA(char *line, t_map_data *map_data)
{
	int	return_value;

	return_value = is_textures(line, 'W', 'E', &map_data->west.path);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = is_textures(line, 'D', 'O', &map_data->door.path);
    if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return (0);
}
