/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/14 21:08:19 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "mlx.h"
# define WIDTH 1300
# define HEIGHT 1000
# define W_IMG  (WIDTH - 200)
# define NTHREAD 8

typedef struct	s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			it_max;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		x;
	double		y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	int			i;
	double		tmp;
	int			mouse_x;
	int			mouse_y;
	double		move_x;
	double		move_y;
	double		zoom;
	void		*image_ptr;
	char		*image_str;
	char		*name;
	double		xtemp;
	double		ytemp;
	void		*(*thread)(void *data);
	int			key_julia;
	int			psycho;
}				t_fract;

typedef struct	s_thread
{
	t_fract		*f;
	double		x_start;
	double		y_start;
	double		x_end;
	double		y_end;
}				t_thread;

void			ft_fractal_init(t_fract *f);
void			ft_draw_image(t_fract *f);
void			launch_threads(t_fract *fract, int n);
void			mlx_put_pixel_img(char *image_str, int x, int y, int color);
void			*ft_mandelbrot(void *data);
void			*ft_julia(void *data);
void			*ft_tricorn(void *data);
int				ft_opti(double x, double y);
int				deal_mouse(int button, int x, int y, t_fract *f);
int				mouse_move(int x, int y, t_fract *f);
int				deal_key(int key, t_fract *f);
int				ft_get_rgb_smooth(int i, int t_max);
void			ft_zoom(t_fract *f);
void			ft_instructions(void *mlx_ptr, void *win_ptr);
int				move_julia(int x, int y, t_fract *f);
#endif
