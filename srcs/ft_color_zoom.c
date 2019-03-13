/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:03:02 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/12 00:11:54 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int 	ft_get_rgb_smooth(int i, int i_max)
{
	double	t;
	int 	color;

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

static void	zoom_init(t_fract *f, double m_r, double m_i)
{
	double	interpolation;

	interpolation = 1.0 / f->zoom;
	f->x1 = inter(m_r, f->x1, interpolation);
	f->y1 = inter(m_i, f->y1, interpolation);
	f->x2 = inter(m_r, f->x2, interpolation);
	f->y2 = inter(m_i, f->y2, interpolation);
}

void	ft_zoom(t_fract *f)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = (double)f->mouse_x / (WIDTH / (f->x2 - f->x1)) + f->x1;
	mouse_i = (double)f->mouse_y / (HEIGHT / (f->y2 - f->y1)) + f->y1;
	zoom_init(f, mouse_r, mouse_i);
}
