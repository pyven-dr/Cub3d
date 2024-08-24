/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:08:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/24 03:42:12 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"

int	key_press(int key, t_keys *keys)
{
	if (key == W)
		keys->forward = 1;
	else if (key == S)
		keys->backward = 1;
	else if (key == D)
		keys->right = 1;
	else if (key == A)
		keys->left = 1;
	else if (key == ESCAPE)
		keys->esc = 1;
	return (0);
}

int	key_release(int key, t_keys *keys)
{
	if (key == W)
		keys->forward = 0;
	else if (key == S)
		keys->backward = 0;
	else if (key == D)
		keys->right = 0;
	else if (key == A)
		keys->left = 0;
	return (0);
}
