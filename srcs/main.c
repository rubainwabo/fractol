/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:57:26 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 23:10:52 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

void	ft_draw_image(t_fract *f)
{
	launch_threads(f);
	//f->thread(&(t_thread){.x_start = 0, .y_start = 0, .y_end = HEIGHT, .x_end = WIDTH, .f = f});
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->image_ptr, 0, 0);
	//mlx_destroy_image(f->mlx_ptr, f->image_ptr);
}

static int ft_check_error(int ac, char *str)
{
	if (ac != 2)
	{
		ft_putendl("Usage: ./fractol Mandelbrot/Julia/fractal_3");
		return (0);
	}
	if (ac == 2 && (ft_strcmp("Mandelbrot", str) &&
		ft_strcmp("Julia", str) && ft_strcmp("fractal_3", str)))
	{
		ft_putendl("Usage: ./fractol Mandelbrot/Julia/fractal_3");
		return (0);
	}
	return (1);
}

static t_fract	*ft_check_fractal(char *str)
{
	t_fract	*f;

	if (!(f = ft_fractal_init(str)))
		exit (0);
	f->move_x = 0;
	f->move_y = 0;
	f->mouse_x = WIDTH / 2;
	f->mouse_y = HEIGHT / 2;
	f->it_max = 100;
	if (!ft_strcmp(str, "Mandelbrot"))
		f->thread = ft_mandelbrot;
	else if (!ft_strcmp(str, "Julia"))
		f->thread = ft_julia;
	else
		f->thread = NULL;
	return (f);
}

int		main(int ac, char **argv)
{
	t_fract	*f;
	int		specs[3];

	if (!ft_check_error(ac, argv[1]))
		return (0);
	if (!(f = ft_check_fractal(argv[1])))
		return (0);
	f->mlx_ptr = mlx_init();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, "fractol");
	f->image_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->image_str = mlx_get_data_addr(f->image_ptr, &specs[0], &specs[1], &specs[2]);
	ft_draw_image(f);
	mlx_hook(f->win_ptr, 2, 0, deal_key, f);
	mlx_mouse_hook(f->win_ptr, deal_mouse, f);
	mlx_key_hook(f->win_ptr, deal_key, f);
	mlx_loop(f->mlx_ptr);
	return (0);
}
