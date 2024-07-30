/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:54:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 23:54:48 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx.h"
#include "struct.h"
#include <stdlib.h>

int	close_window(void *mlx_struct)
{
	t_mlx	*mlx_data;

	mlx_data = (t_mlx *)mlx_struct;
	mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img_data->img);
	mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->mlx_win);
	mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
	exit(0);
}

int	create_window(t_mlx *mlx_data)
{
	mlx_data->mlx_ptr = mlx_init();
	if (mlx_data->mlx_ptr == NULL)
		return (1);
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx_ptr, WIDTH, \
									HEIGHT, WIN_NAME);
	if (mlx_data->mlx_win == NULL)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		return (1);
	}
	return (0);
}
