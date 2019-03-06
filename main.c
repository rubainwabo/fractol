/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:57:26 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/06 02:54:03 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel_img(char *image_str, int x, int y, int color)
{
	unsigned int	pos;

	pos = (x + WIDTH * y) * 4;
	if (pos <= (WIDTH * HEIGHT * 4))
	{
		image_str[pos] = color & 0xFF;
		image_str[pos + 1] = (color >> 8) & 0xFF;
		image_str[pos + 2] = (color >> 16) & 0xFF;
	}
}

void	ft_draw_image(void *mlx_ptr, void *win_ptr, t_hook *param)
{
	t_fract *f;
	t_fract	fract;
	void	*image_ptr;
	char	*image_str;
	int		specs[3];
	/*double  h;
	double  s;
	double  v;*/
	t_color		*c;

	if (!(f = (t_fract*)malloc(sizeof(t_fract))))
		return ;
	image_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	image_str = mlx_get_data_addr(image_ptr, &specs[0], &specs[1], &specs[2]);
	f->i = -1;
	f->it_max = param->fract.it_max;
	f->x1 = -2.5f;
	f->x2 = 0.6f;
	f->y1 = -1.0f;
	f->y2 = 1.0f;
	f->x = 0.0f;
	while (f->x < WIDTH)
	{
		f->y = 0.0f;
		while (f->y < HEIGHT)
		{
			f->c_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1) * param->e.zoom;
			f->c_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1) * param->e.zoom;
			f->z_r = 0;
			f->z_i = 0;
			f->i = 0;
			do
			{
				//if (!(ft_opti(f->c_r, f->c_i)))
					//break;
				f->tmp = f->z_r;
				f->z_r = f->z_r * f->z_r - f->z_i * f->z_i + f->c_r;
				f->z_i = 2 * f->z_i * f->tmp + f->c_i;
				f->i++;
			} while (f->z_r * f->z_r + f->z_i * f->z_i <= (1 << 16) && f->i < f->it_max);
			/*if (f->i < f->it_max)
			{
				double log_z = log(f->z_r * f->z_r + f->z_i * f->z_i) / 2;
				double nu = log(log_z / log(2)) / log(2);
				f->i = f->i + 1 - nu;
			}*/
			/*h = (360 * f->i / f->it_max);
			s = 255;
			if (f->i < f->it_max)
				v = 255;
			else
				v = 0;
			//printf("2\n");*/
			//ft_zoom(param, f);
			c = ft_init();
			ft_get_rgb_smooth(c, f->i, f->it_max);
			//ft_hsv2rgb(c, h, s, v);
			//printf("x = %f and y = %f\n", f->x, f->y);
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x + param->e.move_x, f->y + param->e.move_y, 0x0);
			else
				mlx_put_pixel_img(image_str, f->x + param->e.move_x, f->y + param->e.move_y, ((c->r << 16) | (c->g << 8) | c->b));
			f->y++;
		}
		f->x++;
	}

	mlx_put_image_to_window(mlx_ptr, win_ptr, image_ptr, 0, 0);
	mlx_destroy_image(mlx_ptr, image_ptr);
}

int		main(int ac, char **argv)
{
	t_hook	*param;

	if (!(param = (t_hook*)malloc(sizeof(t_hook))))
	{
		perror("malloc failied");
		return (0);
	}
	param->e.zoom = 1;
	param->e.move_x = 0;
	param->e.move_y = 0;
	param->fract.it_max = 50;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fractol");
	ft_draw_image(param->mlx_ptr, param->win_ptr, param);
	mlx_mouse_hook(param->win_ptr, deal_mouse, param);
	mlx_key_hook(param->win_ptr, deal_key, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
