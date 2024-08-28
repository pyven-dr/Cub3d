/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:52:05 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 22:52:05 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "mlx.h"

int	open_xpm(void *mlx_ptr, t_data *nsew, char *path)
{
	nsew->img = mlx_xpm_file_to_image(mlx_ptr, \
	path, &nsew->width, &nsew->height);
	if (nsew->img == NULL)
		return (1);
	nsew->addr =mlx_get_data_addr(nsew->img, &nsew->bits_per_pixel, \
	&nsew->line_length, &nsew->endian);
	if (nsew->addr == NULL)
	{
		mlx_destroy_image(mlx_ptr, nsew->img);
		return (1);
	}
	return (0);
}
