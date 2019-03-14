#include "fractol.h"

// void	*ft_julia(void *data)
// {
// 	t_thread *d = (t_thread *) data;

// 	d->f->x = d->x_start - 1;
// 	while (++d->f->x < d->x_end)
// 	{
// 		d->f->y = d->y_start - 1;
// 		while(++d->f->y < d->y_end)
// 		{
// 			d->f->z_r = d->f->x1 + (double)(d->f->x / WIDTH) * (d->f->x2 - d->f->x1) + d->f->move_x;
// 			d->f->z_i = d->f->y1 + (d->f->y / HEIGHT) * (d->f->y2 - d->f->y1) + d->f->move_y;
// 			d->f->i = -1;
// 			while (d->f->z_r * d->f->z_r + d->f->z_i * d->f->z_i < 1 << 16 && ++d->f->i < d->f->it_max)
// 			{
// 				d->f->tmp = d->f->z_r * d->f->z_r - d->f->z_i * d->f->z_i + d->f->c_r;
// 				d->f->z_i = 2 * d->f->z_r * d->f->z_i + d->f->c_i;
// 				d->f->z_r = d->f->tmp;
// 			}
// 			if (d->f->i == d->f->it_max)
// 				mlx_put_pixel_img(d->f->image_str, d->f->x, d->f->y, 0x0);
// 			else if (d->f->i % 4 == 0)
// 				mlx_put_pixel_img(d->f->image_str, d->f->x, d->f->y, 0x9988de * d->f->i);
// 			else if (d->f->i % 3 == 0)
// 				mlx_put_pixel_img(d->f->image_str, d->f->x, d->f->y, 0x8899de * d->f->i);
// 			else
// 				mlx_put_pixel_img(d->f->image_str, d->f->x, d->f->y, ft_get_rgb_smooth(d->f->i,
// 					d->f->it_max));
// 		}
// 	}
// 	return (0);
// }

void	*ft_julia(void *data)
{
	t_thread *d = (t_thread *) data;

	d->f->x = d->x_start - 1;
	register double z_r = d->f->z_r;
	register double z_i = d->f->z_i;
	register int	i = d->f->i;
	register double y = d->f->y;
	register double x = d->f->x;
	register double y1 = d->f->y1;
	register double x1 = d->f->x1;
	register double y2 = d->f->y2;
	register double x2 = d->f->x2;
	register double tmp = d->f->tmp;

	while (++x< d->x_end)
	{
		y = d->y_start - 1;
		while(++y < d->y_end)
		{
			z_r = x1 + (x / WIDTH) * (x2 - x1) + d->f->move_x;
			z_i = y1 + (y / HEIGHT) * (y2 - y1) + d->f->move_y;
			i = -1;
			while (z_r * z_r + z_i * z_i < 1 << 16 && ++i < d->f->it_max)
			{
				tmp = z_r * z_r - z_i * z_i + d->f->c_r;
				z_i = 2 * z_r * z_i + d->f->c_i;
				z_r = tmp;
			}
			if (i == d->f->it_max)
				mlx_put_pixel_img(d->f->image_str, x, y, 0x0);
			else if (i % 4 == 0)
				mlx_put_pixel_img(d->f->image_str, x, y, 0x9988de * i);
			else if (i % 3 == 0)
				mlx_put_pixel_img(d->f->image_str, x, y, 0x8899de * i);
			else
				mlx_put_pixel_img(d->f->image_str, x, y, ft_get_rgb_smooth(i,
					d->f->it_max));
		}
	}
	return (0);
}


/*void	ft_julia(char *image_str, t_hook *p, t_fract *f)
{
	d->f->x = -1;
	while (++f->x < WIDTH)
	{
		d->f->y = -1;
		while(++f->y < HEIGHT)
		{
			f->c_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1) + p->move_x;
			f->c_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1) + p->move_y;
			f->z_r = 0;
			f->z_i = 0;
			f->i = -1;
			while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && ++f->i < f->it_max)
			{
				f->tmp = pow((f->z_r * f->z_r + f->z_i * f->z_i), (p->fract->n / 2)) *
				cos(p->fract->n * atan2(f->z_i, f->z_r)) + f->c_r;
				f->z_i = pow((f->z_r * f->z_r + f->z_i * f->z_i), (p->fract->n / 2)) *
				sin(p->fract->n * atan2(f->z_i, f->z_r)) + f->c_i;
				f->z_r = f->tmp;
			}
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x0);
			else
				mlx_put_pixel_img(image_str, f->x, f->y, ft_get_rgb_smooth(f->i,
					f->it_max));
		}
	}
}*/