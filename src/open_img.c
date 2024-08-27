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

#include "mlx.h"
#include "mlx_funcs.h"
#include "map.h"
#include "libft.h"

int	open_xpm(void *mlx_ptr, t_data *nsew, char *path)
{
	nsew->img = mlx_xpm_file_to_image(mlx_ptr, \
	path, &nsew->width, &nsew->height);
	if (nsew->img == NULL)
		return (1);
	nsew->addr = mlx_get_data_addr(nsew->img, &nsew->bits_per_pixel, \
	&nsew->line_length, &nsew->endian);
	if (nsew->addr == NULL)
		return (1);
	return (0);
}

int	open_img(t_map_data *map_data, void *mlx_ptr)
{
	if (open_xpm(mlx_ptr, &map_data->menu, "./menu.xpm") == 1)
	{
		ft_putstr_fd("Error while opening the menu img\n", 2);
		return (1);
	}
	if (open_xpm(mlx_ptr, &map_data->hood, "./hood.xpm") == 1)
	{
		ft_putstr_fd("Error while opening the hood img\n", 2);
		mlx_destroy_image(mlx_ptr, map_data->menu.img);
		return (1);
	}
	if (open_xpm(mlx_ptr, &map_data->map_img, "./map_back.xpm") == 1)
	{
		ft_putstr_fd("Error while opening the map_back img\n", 2);
		mlx_destroy_image(mlx_ptr, map_data->hood.img);
		mlx_destroy_image(mlx_ptr, map_data->menu.img);
		return (1);
	}
	if (open_object_img(&map_data->object, mlx_ptr) == 1)
	{
		mlx_destroy_image(mlx_ptr, map_data->hood.img);
		mlx_destroy_image(mlx_ptr, map_data->menu.img);
		mlx_destroy_image(mlx_ptr, map_data->map_img.img);
		return (1);
	}
	return (0);
}
