/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 06:29:07 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 06:29:07 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "map.h"
#include "mlx.h"
#include "libft.h"

static int	open_object_use(t_object *object, void *mlx_ptr)
{
	if (open_xpm(mlx_ptr, &object->object_use1, OBJ_USE1_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the object_use1 img\n", 2);
		return (1);
	}
	if (open_xpm(mlx_ptr, &object->object_use2, OBJ_USE2_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the object_use2 img\n", 2);
		mlx_destroy_image(mlx_ptr, object->object_use1.img);
		return (1);
	}
	if (open_xpm(mlx_ptr, &object->object_use3, OBJ_USE3_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the object_use3 img\n", 2);
		mlx_destroy_image(mlx_ptr, object->object_use1.img);
		mlx_destroy_image(mlx_ptr, object->object_use2.img);
		return (1);
	}
	return (0);
}

int	open_object_img(t_object *object, void *mlx_ptr)
{
	if (open_xpm(mlx_ptr, &object->object_idle, OBJ_IDLE_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the object_idle img\n", 2);
		return (1);
	}
	if (open_xpm(mlx_ptr, &object->object_use_sec, OBJ_SEC_USE_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the object_use_sec img\n", 2);
		mlx_destroy_image(mlx_ptr, object->object_idle.img);
		return (1);
	}
	if (open_object_use(object, mlx_ptr) == 1)
	{
		mlx_destroy_image(mlx_ptr, object->object_idle.img);
		mlx_destroy_image(mlx_ptr, object->object_use_sec.img);
		return (1);
	}
	return (0);
}
