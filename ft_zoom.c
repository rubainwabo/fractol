/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 23:03:02 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/06 02:36:59 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	inter(double start, double end, double inter)
{
	return (start + (end - start) * inter);
}

void	zoom_init(t_fract *f, double m_r, double m_i, double zoom)
{
	double	interpolation;

	interpolation = 1.0 / zoom;
	f->x1 = inter(m_r, f->x1, interpolation);
	f->y1 = inter(m_i, f->y1, interpolation);
	f->x2 = inter(m_r, f->x2, interpolation);
	f->y2 = inter(m_i, f->y2, interpolation);
}

void	ft_zoom(t_hook *p, t_fract *f)
{
	double	mouse_r;
	double	mouse_i;

	mouse_r = (double)p->e.mouse_x / (WIDTH / (f->x2 - f->x1)) + f->x1;
	mouse_i = (double)p->e.mouse_y / (HEIGHT / (f->y2 - f->y1)) + f->y1;
	zoom_init(f, mouse_r, mouse_i, p->e.zoom);
}
