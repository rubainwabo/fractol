/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:57:26 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/01 23:30:09 by rkamegne         ###   ########.fr       */
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

void	ft_draw_image(void	*mlx_ptr, void *win_ptr, t_hook *param)
{
	t_fract fract;
	void	*image_ptr;
	char	*image_str;
	int		specs[3];
	int		colour[3] = {0x990000, 0x009900, 0x990000};
	int		n;
	int		d;

	image_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	image_str = mlx_get_data_addr(image_ptr, &specs[0], &specs[1], &specs[2]);
	fract.i = -1;
	fract.zoom = param->fract.zoom;
	fract.it_max = param->fract.it_max;
	fract.x1 = -2.5f;
	fract.x2 = 0.6f;
	fract.y1 = -1.0f;
	fract.y2 = 1.0f;
	fract.x = 0.0f;
	fract.image_x = (fract.x2 - fract.x1) * fract.zoom;
	fract.image_y = (fract.y2 - fract.y1) * fract.zoom;
	n = 0;
	while (++fract.i < fract.it_max)
	{
		if (n > 3)
			n = 0;
		fract.color[fract.i] = (int) (fract.i * colour[n]);
		n++;
	}
	while (fract.x < WIDTH)
	{
		fract.y = 0.0f;
		while (fract.y < HEIGHT)
		{
			fract.c_r =  /*fract.x / fract.zoom + fract.x1;*/  fract.x1 + (fract.x / WIDTH) * (fract.x2 - fract.x1);
			fract.c_i =  /*fract.y / fract.zoom + fract.y1;*/  fract.y1 + (fract.y / HEIGHT) * (fract.y2 - fract.y1);
			fract.z_r = 0;
			fract.z_i = 0;
			fract.i = 0;
			do
			{
				if (!(ft_opti(fract.c_r, fract.c_i)))
					break;
				fract.tmp = fract.z_r;
				fract.z_r = fract.z_r * fract.z_r - fract.z_i * fract.z_i + fract.c_r;
				fract.z_i = 2 * fract.z_i * fract.tmp + fract.c_i;
				fract.i++;
			} while (fract.z_r * fract.z_r + fract.z_i * fract.z_i <= (1 << 16) && fract.i < fract.it_max);
			if (fract.i == fract.it_max)
				mlx_put_pixel_img(image_str, fract.x, fract.y, 0x0);
			else if (fract.i == 0)
				mlx_put_pixel_img(image_str, fract.x, fract.y, 0x0);			
			else if (fract.i != fract.it_max)
				mlx_put_pixel_img(image_str, fract.x, fract.y, fract.color[fract.i]);//RGB(0, 0, fract.color[fract.i])); 
			fract.y++;
		}
		fract.x++;
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
	param->fract.zoom = 400;
	param->fract.it_max = 50;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fractol");
	ft_draw_image(param->mlx_ptr, param->win_ptr, param);
	mlx_mouse_hook(param->win_ptr, deal_mouse, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
