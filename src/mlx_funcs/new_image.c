/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:56:45 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 23:56:45 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx.h"
#include "struct.h"
#include <stdlib.h>

int	new_image(t_mlx *mlx)
{
	mlx->img_data.img = mlx_new_image(mlx->mlx_ptr, \
										WIDTH, HEIGHT);
	if (mlx->img_data.img == NULL)
		return (1);
	mlx->img_data.addr = mlx_get_data_addr(mlx->img_data.img, \
		&mlx->img_data.bits_per_pixel, &mlx->img_data.line_length, \
		&mlx->img_data.endian);
	return (0);
}
