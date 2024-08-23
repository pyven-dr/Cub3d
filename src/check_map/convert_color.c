/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:15:29 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/23 01:41:07 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	convert_color(char *line, t_color *color)
{
	if (color->hexa != 0)
		return (-1);
	while (*line < '0' || *line > '9')
		line++;
	color->r = ft_atoi(line);
	if (color->r < 0 || color->r > 255)
		return (-1);
	while (line && *line != ',')
		line++;
	color->g = ft_atoi(++line);
	if (color->g < 0 || color->g > 255)
		return (-1);
	while (line && *line != ',')
		line++;
	color->b = ft_atoi(++line);
	if (color->b < 0 || color->b > 255)
		return (-1);
	while (*line >= '0' && *line <= '9')
		line++;
	if (*line != '\n' && *line != '\0')
		return (-1);
	color->hexa = create_rgb(color->r, color->g, color->b);
	return (0);
}
