/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 02:08:48 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/08/26 00:54:00 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "const_values.h"
#include "game_loop.h"

int	key_player_control(int key, t_keys *keys)
{
	if (key == W)
		keys->forward = 1;
	else if (key == S)
		keys->backward = 1;
	else if (key == A)
		keys->left = 1;
	else if (key == D)
		keys->right = 1;
	else if (key == RIGHT_ARROW)
		keys->look_right = 1;
	else if (key == LEFT_ARROW)
		keys->look_left = 1;
	else if (key == UP_ARROW)
		keys->up = 1;
	else if (key == DOWN_ARROW)
		keys->down = 1;
	else if (key == CTRL)
		keys->crouch = 1;
	else if (key == SPACE)
		keys->fly = 1;
	return (0);
}

void	enable_mouse(t_keys *keys)
{
	if (keys->alt == 1)
		keys->alt = 0;
	else
	{
		keys->alt = 1;
		keys->mouse.is_recentering = 0;
		keys->mouse.x = WIDTH / 2;
		keys->mouse.y = HEIGHT / 2;
	}
}

int	key_press(int key, t_keys *keys)
{
	if (keys->menu == 1)
		keys->menu = 0;
	if (key == ESCAPE)
		keys->esc = 1;
	else if (key == ALT)
		enable_mouse(keys);
	else if (key == C)
	{
		if (keys->hood == 1)
			keys->hood = 0;
		else
			keys->hood = 1;
	}
	else
		key_player_control(key, keys);
	return (0);
}

int	key_release(int key, t_keys *keys)
{
	if (key == W)
		keys->forward = 0;
	else if (key == S)
		keys->backward = 0;
	else if (key == RIGHT_ARROW)
		keys->look_right = 0;
	else if (key == LEFT_ARROW)
		keys->look_left = 0;
	else if (key == UP_ARROW)
		keys->up = 0;
	else if (key == DOWN_ARROW)
		keys->down = 0;
	else if (key == CTRL)
		keys->crouch = 0;
	else if (key == SPACE)
		keys->fly = 0;
	else if (key == A)
		keys->left = 0;
	else if (key == D)
		keys->right = 0;
	return (0);
}
