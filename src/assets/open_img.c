/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 02:44:31 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 02:44:31 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "mlx.h"
#include "mlx_funcs.h"
#include "map.h"
#include "libft.h"

static void	close_img(t_map_data *map_data, void *mlx_ptr)
{
	if (map_data->menu.img != NULL)
		mlx_destroy_image(mlx_ptr, map_data->menu.img);
	if (map_data->hood.img != NULL)
		mlx_destroy_image(mlx_ptr, map_data->hood.img);
	if (map_data->map_img.img != NULL)
		mlx_destroy_image(mlx_ptr, map_data->map_img.img);
}

int	open_img(t_map_data *map_data, void *mlx_ptr)
{
	if (open_xpm(mlx_ptr, &map_data->menu, MENU_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the menu img\n", 2);
		return (1);
	}
	if (open_xpm(mlx_ptr, &map_data->hood, HOOD_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the hood img\n", 2);
		close_img(map_data, mlx_ptr);
		return (1);
	}
	if (open_xpm(mlx_ptr, &map_data->map_img, MAP_PATH) == 1)
	{
		ft_putstr_fd("Error while opening the map_back img\n", 2);
		close_img(map_data, mlx_ptr);
		return (1);
	}
	if (open_object_img(&map_data->object, mlx_ptr) == 1)
	{
		close_img(map_data, mlx_ptr);
		return (1);
	}
	return (0);
}
