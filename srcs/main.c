/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:57:26 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/14 20:50:37 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			mlx_put_pixel_img(char *image_str, int x, int y, int color)
{
	unsigned int	pos;

	pos = (x + W_IMG * y) * 4;
	if (pos <= (W_IMG * HEIGHT * 4))
	{
		image_str[pos] = color & 0xFF;
		image_str[pos + 1] = (color >> 8) & 0xFF;
		image_str[pos + 2] = (color >> 16) & 0xFF;
	}
}

void			ft_draw_image(t_fract *f)
{
	launch_threads(f, NTHREAD);
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image_ptr, 0, 0);
}

static int		ft_check_error(int ac, char *str)
{
	if (ac != 2)
	{
		ft_putendl("Usage: ./fractol Mandelbrot/Julia/Tricorn");
		return (0);
	}
	if (ac == 2 && (ft_strcmp("Mandelbrot", str) &&
		ft_strcmp("Julia", str) && ft_strcmp("Tricorn", str)))
	{
		ft_putendl("Usage: ./fractol Mandelbrot/Julia/Tricorn");
		return (0);
	}
	return (1);
}

static t_fract	*ft_check_fractal(char *str)
{
	t_fract	*f;

	if (!(f = (t_fract*)malloc(sizeof(*f))))
		exit(0);
	f->name = str;
	ft_fractal_init(f);
	return (f);
}

int				main(int ac, char **argv)
{
	t_fract	*f;
	int		specs[3];

	if (!ft_check_error(ac, argv[1]))
		return (0);
	if (!(f = ft_check_fractal(argv[1])))
		return (0);
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "fractol");
	f->image_ptr = mlx_new_image(f->mlx_ptr, W_IMG, HEIGHT);
	f->image_str = mlx_get_data_addr(f->image_ptr, &specs[0], &specs[1],
			&specs[2]);
	ft_draw_image(f);
	ft_instructions(f->mlx_ptr, f->win_ptr);
	mlx_hook(f->win_ptr, 6, 1L << 6, move_julia, f);
	mlx_mouse_hook(f->win_ptr, deal_mouse, f);
	mlx_key_hook(f->win_ptr, deal_key, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
