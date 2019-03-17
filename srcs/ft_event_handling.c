/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 23:24:53 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/17 16:36:46 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		deal_clicks(int x, int y, t_fract *f)
{
	if (x >= W_IMG + 5 && x <= WIDTH && y >= 170 && y <= 200)
	{
		f->name = "Mandelbrot";
		ft_fractal_init(f);
	}
	if (x >= W_IMG + 5 && x <= WIDTH && y >= 210 && y <= 240)
	{
		f->name = "Julia";
		ft_fractal_init(f);
	}
	if (x >= W_IMG + 5 && x <= WIDTH && y >= 250 && y <= 280)
	{
		f->name = "Tricorn";
		ft_fractal_init(f);
	}
	if (x > WIDTH - 185 && x < WIDTH - 15 &&
		y > HEIGHT - 185 && y < HEIGHT - 15)
	{
		f->color = ft_color_fractal(x, y);
		f->coloured = 1;
	}
}

int				deal_mouse(int button, int x, int y, t_fract *f)
{
	f->mouse_x = x;
	f->mouse_y = y;
	if (button == 4)
	{
		f->zoom = 2.01;
		ft_zoom(f);
	}
	if (button == 5)
	{
		f->zoom = 1 / 2.01;
		ft_zoom(f);
	}
	if (button == 1)
	{
		if (x >= W_IMG + 5 && x <= WIDTH && y >= 290 && y <= 320)
		{
			f->name = "Burning_ship";
			ft_fractal_init(f);
		}
		deal_clicks(x, y, f);
	}
	ft_draw_image(f);
	return (0);
}

static int		deal_key_sec(int key, t_fract *f)
{
	if (key == 82)
		f->key_julia = !f->key_julia;
	if (key == 53)
	{
		mlx_destroy_image(f->mlx_ptr, f->image_ptr);
		(void)f;
		exit(0);
	}
	return (0);
}

int				deal_key(int key, t_fract *f)
{
	if (key == 124)
		f->move_x -= (0.2 * (f->x2 - f->x1) / 3.1);
	else if (key == 123)
		f->move_x += (0.2 * (f->x2 - f->x1) / 3.1);
	else if (key == 125)
		f->move_y += (0.2 * (f->y2 - f->y1) / -2.4);
	else if (key == 126)
		f->move_y -= (0.2 * (f->y2 - f->y1) / -2.4);
	else if (key == 69)
		f->it_max += 15;
	else if (key == 78)
		f->it_max -= 15;
	else if (key == 15)
		ft_fractal_init(f);
	else
		deal_key_sec(key, f);
	ft_draw_image(f);
	return (0);
}

int				move_julia(int x, int y, t_fract *f)
{
	if (!ft_strcmp(f->name, "Julia") && f->key_julia != 0)
	{
		f->c_r = -2.5 + (double)x / 2300 * 3.5;
		f->c_i = -1.0 + (double)y / 1100 * 2.0;
	}
	ft_draw_image(f);
	return (0);
}
