/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:15:29 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/28 00:29:42 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"
#include "ft_printf.h"

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static char	*pass_number(char *line)
{
	while ((*line >= '0' && *line <= '9'))
		++line;
	return (line);
}

static char	*fill_color(char *line, int *color)
{
	*color = ft_atoi(line);
	if (*color > 255 || *color < 0)
	{
		ft_printf(2, "Color range between 0 and 255\n");
		return (NULL);
	}
	line = pass_number(line);
	return (line);
}
#include <stdio.h>

int	convert_color(char *line, t_color *color)
{
	if (color->hexa != -1)
		return (-1);
	while (*line == ' ')
		line++;
	if (!(*line >= '0' && *line <= '9'))
		return (-1);
	line = fill_color(line, &color->r);
	if (!line || *line++ != ',')
		return (-1);
	if (!(*line >= '0' && *line <= '9'))
		return (-1);
	line = fill_color(line, &color->g);
	if (!line || *line++ != ',')
		return (-1);
	if (!(*line >= '0' && *line <= '9'))
		return (-1);
	line = fill_color(line, &color->b);
	if (!line || *line != '\n')
		return (-1);
	color->hexa = create_rgb(color->r, color->g, color->b);
	dprintf(2, "color hexa :%d\n", color->hexa);
	return (0);
}
