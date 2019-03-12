#include "../includes/fractol.h"

/*void	ft_julia(char *image_str, t_hook *p, t_fract *f)
{
	f->x = -1;
	while (++f->x < WIDTH)
	{
		f->y = -1;
		while(++f->y < HEIGHT)
		{
			f->z_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1) + 0.9 + p->move_x;
			f->z_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1) + p->move_y;
			//f->z_r = 0;
			//f->z_i = 0;
			f->i = -1;
			while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && ++f->i < f->it_max)
			{
				f->tmp = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = 2 * f->z_r * f->z_i + f->c_i;
				f->z_r = f->tmp;
			}
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x0);
			else if (f->i % 4 == 0)
				mlx_put_pixel_img(image_str, f->x, f->y, 0xaaffde * f->i);
			else if (f->i % 3 == 0)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x8899de * f->i);
			else
				mlx_put_pixel_img(image_str, f->x, f->y, ft_get_rgb_smooth(f->i,
					f->it_max));
		}
	}
}*/

void	ft_julia(char *image_str, t_hook *p, t_fract *f)
{
	f->x = -1;
	while (++f->x < WIDTH)
	{
		f->y = -1;
		while(++f->y < HEIGHT)
		{
			f->z_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1) + p->move_x;
			f->z_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1) + p->move_y;
			//f->z_r = 0;
			//f->z_i = 0;
			f->i = -1;
			while (f->z_r * f->z_r + f->z_i * f->z_i < 4 && ++f->i < f->it_max)
			{
				f->tmp = pow((f->z_r * f->z_r + f->z_i * f->z_i), (p->fract->n / 2)) *
				cos(p->fract->n * atan2(f->z_i, f->z_r)) - 0.7;
				f->z_i = pow((f->z_r * f->z_r + f->z_i * f->z_i), (p->fract->n / 2)) *
				sin(p->fract->n * atan2(f->z_i, f->z_r)) + 0.27015;
				f->z_r = f->tmp;
			}
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x0);
			else
				mlx_put_pixel_img(image_str, f->x, f->y, ft_get_rgb_smooth(f->i,
					f->it_max));
		}
	}
}