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

t_fract	*init_fract(void)
{
	t_fract	*f;

	if (!(f = (t_fract*)malloc(sizeof(*f))))
		return (NULL);
	f->x1 = -2.5f;
	f->x2 = 0.6f;
	f->y1 = 1.2f;
	f->y2 = -1.2f;
	return (f);
}

void	ft_draw_image(void *mlx_ptr, void *win_ptr, t_hook *param, t_fract *f)
{
	void	*image_ptr;
	char	*image_str;
	float	zr_s;
	float	zi_s;
	float	z_i;
	float	xtemp;
	float	ytemp;
	int		specs[3];
	/*double  h;
	double  s;
	double  v;*/	
	t_color		*c;

	image_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	image_str = mlx_get_data_addr(image_ptr, &specs[0], &specs[1], &specs[2]);
	f->x = 0.0f;
	while (f->x < WIDTH)
	{
		f->y = 0.0f;
		while (f->y < HEIGHT)
		{
			f->c_r = f->x1 + (f->x / WIDTH) * (f->x2 - f->x1);
			f->c_i = f->y1 + (f->y / HEIGHT) * (f->y2 - f->y1);
			f->z_r = 0;
			f->z_i = 0;
			f->i = 0;
			zr_s = f->z_r * f->z_r;
			zi_s = f->z_i * f->z_i;
			if (!(ft_opti(f->c_r, f->c_i)))
				f->i = f->it_max;
			else
			{
				while (zr_s + zi_s <= (1 << 16) && f->i < f->it_max)
				{
					//if (!(ft_opti(f->x, f->y)))
						//break;
					f->tmp = f->z_r;
					xtemp = zr_s - zi_s + f->c_r;	
					ytemp = (f->z_i + f->z_i) * f->tmp + f->c_i;
					if (f->z_r = xtemp && f->z_i == ytemp)
					{
						f->i = f->it_max;
						break;
					}
					f->z_r = xtemp;
					f->z_i = ytemp;
					zr_s = pow(f->z_r, 2);
					zi_s = pow(f->z_i, 2);
					f->i++;
				}
				c = ft_init();
				ft_get_rgb_smooth(c, f->i, f->it_max);
			}
			if (f->i == f->it_max)
				mlx_put_pixel_img(image_str, f->x, f->y, 0x0);
			else
				mlx_put_pixel_img(image_str, f->x, f->y, ((c->r << 16) | (c->g << 8) | c->b));
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
	t_fract	*f;

	if (!(param = (t_hook*)malloc(sizeof(t_hook))))
	{
		perror("malloc failed");
		return (0);
	}
	if (!(f = init_fract()))
	{
		perror("malloc failed");
		return (0);
	}
	param->e.zoom = 2.01;
	param->e.move_x = 0;
	param->e.move_y = 0;
	f->it_max = 50;
	param->fract = f;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fractol");
	ft_draw_image(param->mlx_ptr, param->win_ptr, param, f);
	mlx_mouse_hook(param->win_ptr, deal_mouse, param);
	mlx_key_hook(param->win_ptr, deal_key, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
