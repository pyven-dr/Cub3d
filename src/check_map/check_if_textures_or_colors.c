/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_textures_or_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:45:39 by tcoze             #+#    #+#             */
/*   Updated: 2024/09/01 04:08:11 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

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

int	check_textures_colors(char *line, t_map_data *map_data)
{
	int	return_value;

	return_value = check_textures_no_so_ea(line, map_data);
	if (return_value == 1)
		return (1);
	if (return_value == -1)
		return (-1);
	return_value = check_textures_we_do(line, map_data);
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
