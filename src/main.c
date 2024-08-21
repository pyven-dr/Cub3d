/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:18:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 04:18:28 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "mlx_funcs.h"
#include "game_loop.h"
#include "const_values.h"
#include <math.h>
#include <stdlib.h>
#include "check_map.h"

int main(int argc, char **argv)
{
	t_true_map	true_map;

	//mlx_data.mlx_ptr = mlx_init();
	//if (mlx_data.mlx_ptr == NULL)
	//	return (1);
	if (pre_parsing(argc, argv, &true_map) == -1)
		return (-1);
	return (0);
}