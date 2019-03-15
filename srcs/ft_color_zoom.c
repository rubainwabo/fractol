/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:03:02 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/14 20:53:35 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				ft_get_rgb_smooth(int i, int i_max)
{
	double	t;
	int		color;

	t = (double)i / (double)i_max;
	color = (int)(9 * (1 - t) * t * t * t * 255) << 16;
	color |= (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8;
	color |= (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return (color);
}

static double	inter(double start, double end, double inter)
{
	return (start + (end - start) * inter);
}

static void		zoom_init(t_fract *f, double m_r, double m_i)
{
	double	interpolation;

	interpolation = 1.0 / f->zoom;
	f->x1 = inter(m_r, f->x1, interpolation);
	f->y1 = inter(m_i, f->y1, interpolation);
	f->x2 = inter(m_r, f->x2, interpolation);
	f->y2 = inter(m_i, f->y2, interpolation);
}

void			ft_zoom(t_fract *f)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = f->mouse_x / (W_IMG / (f->x2 - f->x1)) + f->x1;
	mouse_i = f->mouse_y / (HEIGHT / (f->y2 - f->y1)) + f->y1;
	zoom_init(f, mouse_r, mouse_i);
}

void			ft_instructions(void *mlx_ptr, void *win_ptr)
{
	int		x;

	x = -1;
	while (++x < HEIGHT)
		mlx_pixel_put(mlx_ptr, win_ptr, W_IMG, x, 0x1ec503);
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 10, 0x1ec503,
			"arrow : move");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 50, 0x1ec503,
			"+/- : iterations");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 90, 0x1ec503,
			"scroll : zoom");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 130, 0x1ec503,
			"r : reset changes");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 170, 0xffff00,
		"Mandelbrot");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 210, 0xffff00,
		"Julia");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 250, 0xffff00,
		"Tricorn");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 290, 0xffff00,
		"B_ship");
	mlx_string_put(mlx_ptr, win_ptr, W_IMG + 5, 330, 0xff0000,
		"lmb : palette");
}
