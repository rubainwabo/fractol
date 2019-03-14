/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 14:01:42 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void ft_mandelbrot_init(t_fract *f)
{
	f->x1 = -2.5;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
}

static void ft_julia_init(t_fract *f)
{
	f->x1 = -2.5;
	f->x2 = 1.0;
	f->y1 = -1.0;
	f->y2 = 1.0;
	f->c_r = - 0.7;
	f->c_i = 0.27015;
}

static void ft_fract3(t_fract *f)
{
	f->x1 = -2.5;
	f->x2 = 0.6;
	f->y1 = 1.2;
	f->y2 = -1.2;
}

t_fract	*ft_fractal_init(char *str)
{
	t_fract	*f;

	if (!(f = (t_fract*)malloc(sizeof(*f))))
		exit (0);
	if (!ft_strcmp(str, "Mandelbrot"))
		ft_mandelbrot_init(f);
	else if (!ft_strcmp(str, "Julia"))
		ft_julia_init(f);
	else if (!ft_strcmp(str, "fract_3"))
		ft_fract3(f);
	else
		exit(0);
	return (f);
}
