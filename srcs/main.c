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

void	ft_draw_image(t_hook *p, t_fract *f)
{
	void	*image_ptr;
	char	*image_str;
	int		specs[3];
	void	(*fptr)(char *, t_hook *, t_fract *);

	image_ptr = mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	image_str = mlx_get_data_addr(image_ptr, &specs[0], &specs[1], &specs[2]);
	if (!ft_strcmp(p->w_fract, "Mandelbrot"))
		fptr = ft_mandelbrot;
	else if (!ft_strcmp(p->w_fract, "Julia"))
		fptr = ft_julia;
	else
		fptr = NULL;
	(*fptr)(image_str, p, f);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, image_ptr, 0, 0);
	mlx_destroy_image(p->mlx_ptr, image_ptr);
}

t_hook	*ft_check_error(int ac, char **argv)
{
	t_hook	*p;

	if (ac < 2 || ac > 3)
	{
		ft_putendl("Usage: ./fractol Mandelbrot/Julia/fractal_3");
		return (0);
	}
	if (ac == 2 && (ft_strcmp("Mandelbrot", argv[1]) &&
		ft_strcmp("Julia", argv[1]) && ft_strcmp("fractal_3", argv[1])))
	{
		ft_putendl("Usage: ./fractol Mandelbrot/Julia/fractal_3");
		return (0);
	}
	if (!(p = (t_hook*)malloc(sizeof(*p))))
	{
		perror("malloc failed");
		return (0);
	}
	return (p);
}

t_fract	*ft_check_fractal(char **argv, t_hook *p)
{
	t_fract	*f;

	if (!(f = ft_fractal_init(argv[1])))
	{
		perror("malloc failed");
		return (0);
	}
	p->move_x = 0;
	p->move_y = 0;
	f->it_max = 50;
	p->fract = f;
	return (f);
}
int		main(int ac, char **argv)
{
	t_hook	*param;
	t_fract	*f;

	if (!(param = ft_check_error(ac, argv)))
		return (0);
	if (!(f = ft_check_fractal(argv, param)))
		return (0);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WIDTH, HEIGHT, "fractol");
	param->w_fract = argv[1];
	ft_draw_image(param, f);
	mlx_hook(param->win_ptr, 6, 1<<0, mouse_move, param);
	mlx_mouse_hook(param->win_ptr, deal_mouse, param);
	mlx_key_hook(param->win_ptr, deal_key, param);
	mlx_loop(param->mlx_ptr);
	return (0);
}
