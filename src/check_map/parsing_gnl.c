/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:17:08 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/23 02:52:43 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"

int	parsing_gnl(int fd, t_map_data *map_data)
{
	char	*line;
	int		j;
	int		return_value;

	j = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	while (line)
	{
		if (line[0] && line[1])
		{
			return_value = check_textures_colors(line, map_data);
			if (return_value == 1)
				;
			else if (return_value == -1)
				return (-1);
			else if (line[0] == ' ' || line[0] == '1')
			{
				while (line[0] == ' ' || line[0] == '1')
				{
					if (map_data->east.path == NULL
						|| map_data->north.path == NULL
						|| map_data->west.path == NULL
						|| map_data->south.path == NULL)
						return (-1);
					map_data->map[j] = ft_strdup(line);
					if (!map_data->map[j])
						return (-1);
					j++;
					free(line);
					line = get_next_line(fd);
					if (!line)
						break ;
					if (line[0] != ' ' && line[0] != '1')
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
