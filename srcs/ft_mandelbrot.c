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

void	ft_mandelbrot(char *image_str, t_color *c, t_hook *p, t_fract *f)
{
	f->x = 0;
	while (f->x < WIDTH)
	{
		f->y = 0;
		while (f->y < HEIGHT)
		{
			f->c_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1) + p->e.move_x;
			f->c_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1) + p->e.move_y;
			f->z_r = 0;
			f->z_i = 0;
			f->i = 0;
			if (!(ft_opti(f->c_r, f->c_i)))
				f->i = f->it_max;
			while (f->z_r * f->z_r + f->z_i * f->z_i <= 1 << 16 && f->i <
				f->it_max)
			{
				f->tmp = f->z_r;
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = (f->z_i + f->z_i) * f->tmp + f->c_i;
				f->i++;
			}
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x0);
			else
			{
				if (!(c = ft_init()))
				{
					perror("Malloc failed");
					return ;
				}
				ft_get_rgb_smooth(c, f->i, f->it_max);
				mlx_put_pixel_img(image_str, f->x, f->y, ((c->r << 16) |
					(c->g << 8) | c->b));
			}
			f->y++;
		}
		f->x++;
	}
}