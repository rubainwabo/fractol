/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/14 20:52:19 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_mandelbrot_init(t_fract *f)
{
	f->x1 = -2.5;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
}

static void		ft_julia_init(t_fract *f)
{
	f->x1 = -2.5;
	f->x2 = 1.0;
	f->y1 = -1.0;
	f->y2 = 1.0;
	f->c_r = -0.7;
	f->c_i = 0.27015;
}

static void		ft_tricorn_init(t_fract *f)
{
	f->x1 = -2.5;
	f->x2 = 1.0;
	f->y1 = -1.0;
	f->y2 = 1.0;
}

void			ft_fractal_init(t_fract *f)
{
	if (!ft_strcmp(f->name, "Mandelbrot"))
	{
		ft_mandelbrot_init(f);
		f->thread = ft_mandelbrot;
	}
	else if (!ft_strcmp(f->name, "Julia"))
	{
		ft_julia_init(f);
		f->thread = ft_julia;
	}
	else
	{
		ft_tricorn_init(f);
		f->thread = ft_tricorn;
	}
	f->move_x = 0;
	f->move_y = 0;
	f->mouse_x = W_IMG / 2;
	f->mouse_y = HEIGHT / 2;
	f->it_max = 50;
	f->key_julia = 0;
	f->psycho = 0;
}
