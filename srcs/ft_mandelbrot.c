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

void	ft_mandelbrot(char *image_str, t_hook *p, t_fract *f)
{
	double	xtemp;
	double	ytemp;

	f->x = -1;
	while (++f->x < WIDTH)
	{
		f->y = -1;
		while (++f->y < HEIGHT)
		{
			f->c_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1) + p->move_x;
			f->c_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1) + p->move_y;
			f->z_r = 0;
			f->z_i = 0;
			f->i = -1;
			if (!(ft_opti(f->c_r, f->c_i)))
				f->i = f->it_max;
			while (f->z_r * f->z_r + f->z_i * f->z_i <= 4 && ++f->i <
				f->it_max)
			{
				f->tmp = f->z_r;
				xtemp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				ytemp = (f->z_i + f->z_i) * f->tmp + f->c_i;
				if (f->z_r == xtemp && f->z_i == ytemp)
				{
					f->i = 40;
					break;
				}
				f->z_r = xtemp;
				f->z_i = ytemp;
			}
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x0);
			else if (f->i == 40)
				mlx_put_pixel_img(image_str, f->x, f->y, 0xff0000);
			else
				mlx_put_pixel_img(image_str, f->x, f->y, ft_get_rgb_smooth(f->i,
					f->it_max));
		}
	}
}