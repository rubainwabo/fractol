/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:57:26 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 14:02:25 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	*ft_mandelbrot(void *data)
{
	t_thread *d = (t_thread *)data;

	d->f->x = d->x_start;
	while (d->f->x < d->x_end)
	{
		d->f->y = d->y_start;
		while (d->f->y < d->y_end)
		{
			d->f->c_r = d->f->x1 + (d->f->x / WIDTH) * (d->f->x2 - d->f->x1) +
			d->f->move_x;
			d->f->c_i = d->f->y1 + (d->f->y / HEIGHT) * (d->f->y2 - d->f->y1) +
			d->f->move_y;
			d->f->z_r = 0;
			d->f->z_i = 0;
			d->f->i = -1;
			if (!(ft_opti(d->f->c_r, d->f->c_i)))
				d->f->i = d->f->it_max;
			while (d->f->z_r * d->f->z_r + d->f->z_i * d->f->z_i <= 1 << 16 &&
				++d->f->i < d->f->it_max)
			{
				d->f->tmp = d->f->z_r;
				d->f->xtemp = d->f->z_r * d->f->z_r - d->f->z_i * d->f->z_i +
				d->f->c_r;
				d->f->ytemp = (d->f->z_i + d->f->z_i) * d->f->tmp + d->f->c_i;
				if (d->f->z_r == d->f->xtemp && d->f->z_i == d->f->ytemp &&
					(d->f->i = d->f->it_max))
					break;
				d->f->z_r = d->f->xtemp;
				d->f->z_i = d->f->ytemp;
			}
			if (d->f->i == d->f->it_max)
				mlx_put_pixel_img(d->f->image_str, d->f->x, d->f->y, 0x0);
			else
				mlx_put_pixel_img(d->f->image_str, d->f->x, d->f->y,
					ft_get_rgb_smooth(d->f->i, d->f->it_max));
			d->f->y++;
		}
		d->f->x++;
	}
	return (0);
}