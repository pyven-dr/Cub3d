/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funcs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 22:19:30 by pyven-dr          #+#    #+#             */
/*   Updated: 2024/07/12 22:19:30 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_FUNCS_H
# define MLX_FUNCS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*path;
	int		width;
	int		height;
}			t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_data	img_data;
}			t_mlx;

void	pixel_put(t_data *data, int x, int y, int color);
int		create_window(t_mlx *mlx_data);
int		new_image(t_mlx *mlx);
int		get_pixel_color(const t_data *img_data, int x, int y);
void	display_img(t_data *img, t_data *background_img);

#endif
