/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nsew_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:19:38 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/24 00:49:36 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"
#include "mlx.h"

static int	file_to_struct(t_game_data *game_data, t_data *nsew)
{
	nsew->img = mlx_xpm_file_to_image(game_data->mlx_data.mlx_ptr,
			nsew->path, &nsew->width, &nsew->height);
	if (nsew->img == NULL)
		return (-1);
	nsew->addr = mlx_get_data_addr(nsew->img, &nsew->bits_per_pixel,
			&nsew->line_length, &nsew->endian);
	if (nsew->addr == NULL)
		return (-1);
	return (0);
}

int	fill_nsew_struct(t_game_data *game_data)
{
	if (file_to_struct(game_data, &game_data->map_data.north) == -1)
		return (-1);
	if (file_to_struct(game_data, &game_data->map_data.south) == -1)
		return (-1);
	if (file_to_struct(game_data, &game_data->map_data.east) == -1)
		return (-1);
	if (file_to_struct(game_data, &game_data->map_data.west) == -1)
		return (-1);
	return (0);
}
