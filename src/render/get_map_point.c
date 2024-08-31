/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 00:50:02 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/21 00:50:02 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "map.h"

char	get_map_point(double x, double y, t_map_data *map)
{
	if ((int)floor(y) >> 6 >= map->map_height || (int)floor(y) >> 6 < 0)
		return (3);
	if ((int)floor(x) >> 6 > (int)ft_strlen(map->map[(int)floor(y) >> 6]) \
		|| (int)floor(x) >> 6 < 0)
		return (3);
	if ((int)floor(y) << 6 < 0 || (int)floor(x) << 6 < 0)
		return (-1);
	return (map->map[((int)floor(y) >> 6)][((int)floor(x) >> 6)]);
}
