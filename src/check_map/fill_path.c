/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 02:47:04 by tcoze             #+#    #+#             */
/*   Updated: 2024/09/01 00:48:06 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	end_line(char *line)
{
	while (line && *line != '\n')
		line++;
	*line = '\0';
}

int	fill_path(char *line, char **path)
{
	int	i;

	i = 2;
	if (*path != NULL)
		return (-1);
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] && line[i + 1] && line[i] != '.' && line[i + 1] != '/')
		return (-1);
	*path = ft_strdup(line + i);
	if (*path == NULL)
		return (-1);
	end_line(*path);
	return (0);
}
