/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:17:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/28 02:17:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "mlx.h"

void	free_obj_img(void *mlx_ptr, t_object *object)
{
	mlx_destroy_image(mlx_ptr, object->object_idle.img);
	mlx_destroy_image(mlx_ptr, object->object_use1.img);
	mlx_destroy_image(mlx_ptr, object->object_use2.img);
	mlx_destroy_image(mlx_ptr, object->object_use3.img);
	mlx_destroy_image(mlx_ptr, object->object_use_sec.img);
}

void	free_img(void *mlx_ptr, t_map_data *map_data)
{
	mlx_destroy_image(mlx_ptr, map_data->menu.img);
	mlx_destroy_image(mlx_ptr, map_data->hood.img);
	mlx_destroy_image(mlx_ptr, map_data->map_img.img);
	free_obj_img(mlx_ptr, &map_data->object);
}