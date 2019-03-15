/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:29:17 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/15 17:36:07 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_loop(t_thread *a, t_thread *d)
{
	a->i = -1;
	while (a->z_r * a->z_r + a->z_i * a->z_i <= 1 << 16 && ++a->i <
		d->f->it_max)
	{
		a->tmp = a->z_r * a->z_r - a->z_i * a->z_i + d->f->c_r;
		a->z_i = 2 * a->z_r * a->z_i + d->f->c_i;
		a->z_r = a->tmp;
	}
}

void		*ft_julia(void *data)
{
	t_thread	*d;
	t_thread	a;

	d = (t_thread *)data;
	ft_fractal_thread(&a, d);
	while (++a.x < d->x_end)
	{
		a.y = d->y_start - 1;
		while (++a.y < d->y_end)
		{
			a.z_r = a.x1 + (a.x / W_IMG) * (a.x2 - a.x1) + 0.755 + d->f->move_x;
			a.z_i = a.y1 + (a.y / HEIGHT) * (a.y2 - a.y1) + d->f->move_y;
			ft_loop(&a, d);
			if (a.i == d->f->it_max)
				mlx_put_pixel_img(d->f->image_str, a.x, a.y, a.i * 0x0);
			if (a.i != d->f->it_max && d->f->coloured)
				mlx_put_pixel_img(d->f->image_str, a.x, a.y, a.i * d->f->color);
			else
				mlx_put_pixel_img(d->f->image_str, a.x, a.y,
					ft_get_rgb_smooth(a.i, d->f->it_max));
		}
	}
	return (0);
}
