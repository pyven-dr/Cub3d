/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_button.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 05:05:02 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/27 05:05:02 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

int	mouse_leave(t_keys *keys)
{
	keys->alt = 0;
	return (0);
}

int	mouse_press(int key, int x, int y, t_keys *keys)
{
	(void)x;
	(void)y;
	if (key == 1)
		keys->object = 1;
	else if (key == 3)
		keys->object_sec = 1;
	return (0);
}

int	mouse_release(int key, int x, int y, t_keys *keys)
{
	(void)x;
	(void)y;
	if (key == 1)
		keys->object = 0;
	else if (key == 3)
		keys->object_sec = 0;
	return (0);
}
