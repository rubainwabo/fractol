/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tricorn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:26:53 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/14 19:26:55 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void 	*ft_tricorn(void *data)
{
	t_thread *d;
	register double z_r;
	register double z_i;
	register double c_r;
	register double c_i;
	register int	i;	
	register double y;
	register double x;
	register double y1;
	register double x1;
	register double y2;
	register double x2;
	register double tmp;
	register int 	psycho;

	d = (t_thread *) data;
	z_r = d->f->z_r;
	z_i = d->f->z_i;
	c_r = d->f->c_r;
	c_i = d->f->c_i;
	i = d->f->i;
	y = d->f->y;
	x = d->f->x;
	y1 = d->f->y1;
	x1 = d->f->x1;
	y2 = d->f->y2;
	x2 = d->f->x2;
	tmp = d->f->tmp;
	psycho = d->f->psycho;
	x = d->x_start - 1;
	while (++x < d->x_end)
	{
		y = d->y_start - 1;
		while (++y < d->y_end)
		{
			c_r = x1 + (x / W_IMG) * (x2 - x1) +
			d->f->move_x;
			c_i = y1 + (y / HEIGHT) * (y2 - y1) +
			d->f->move_y;
			z_r = c_r;
			z_i = c_i;
			i = -1;
			while (z_r * z_r + z_i * z_i <= 1 << 16 &&
				++i < d->f->it_max)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i +
				c_r;
				z_i = -2 * tmp * z_i + c_i;
			}
			if (i == d->f->it_max)
				mlx_put_pixel_img(d->f->image_str, x, y, i * 0x0);
			if (i != d->f->it_max && psycho)
				mlx_put_pixel_img(d->f->image_str, x, y, i * 0x1ce503);
			else
				mlx_put_pixel_img(d->f->image_str, x, y,
					ft_get_rgb_smooth(i, d->f->it_max));
		}
	}
	return (0);
}
