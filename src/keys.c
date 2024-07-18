/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:08:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/13 02:08:48 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "const_values.h"

int	key_press(int key, void *keys_param)
{
	t_keys *keys;

	keys = (t_keys *)keys_param;
	if (key == W)
		keys->forward = 1;
	else if (key == S)
		keys->backward = 1;
	else if (key == D)
		keys->right = 1;
	else if (key == A)
		keys->left = 1;
	return (0);
}

int	key_release(int key, void *keys_param)
{
	t_keys *keys;

	keys = (t_keys *)keys_param;
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