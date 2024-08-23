/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcoze <tcoze@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:14:14 by tcoze             #+#    #+#             */
/*   Updated: 2024/08/23 01:26:01 by tcoze            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"
#include "libft.h"

int	check_cub(char *file)
{
	size_t	len;

	if (!file || ft_strlen(file) < 5)
		return (-1);
	len = ft_strlen(file);
	if (file[len - 1] != 'b')
		return (-1);
	if (file[len - 2] != 'u')
		return (-1);
	if (file[len - 3] != 'c')
		return (-1);
	if (file[len - 4] != '.')
		return (-1);
	return (0);
}
