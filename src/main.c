/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 04:18:28 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/21 22:01:29 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <mlx.h>
#include "mlx_funcs.h"
#include "game_loop.h"
#include "const_values.h"
#include <math.h>
#include <stdlib.h>
#include "check_map.h"

#include <stdio.h>


int main(int argc, char **argv)
{
	t_game_data	game_data;
	
	game_data.mlx_data.mlx_ptr = mlx_init();
	if (pre_parsing(argc, argv, &game_data) == -1)
		return (-1);
	dprintf(2, "TT OK\n");
	return (0);
}