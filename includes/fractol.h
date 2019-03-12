/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/12 00:12:51 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# define WIDTH 600
# define HEIGHT 600
# define MAX(x, y, z) ((x >= y) ? ((x >= z) ? x : z) : ((y >= z) ? y : z))
# define MIN(x, y, z) ((x <= y) ? ((x <= z) ? x : z) : ((y <= z) ? y : z))

typedef struct	s_fract
{
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
	int 		n;
	double		tmp;
}				t_fract;

typedef struct	s_hook
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			mouse_x;
	int			mouse_y;
	double		move_x;
	double		move_y;
	double		zoom;
	t_fract		*fract;
	char		*w_fract;
}				t_hook;

t_hook	*ft_check_error(int ac, char **argv);
t_fract	*ft_fractal_init(char *str);
void	ft_draw_image(t_hook *param, t_fract *f);
void	mlx_put_pixel_img(char *image_str, int x, int y, int color);
void	ft_mandelbrot(char *image_str, t_hook *p, t_fract *f);
void	ft_julia(char *image_str, t_hook *p, t_fract *f);
int		ft_opti(double x, double y);
int		deal_mouse(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		deal_key(int key, void *param);
int		ft_get_rgb_smooth(int i, int t_max);
void	ft_zoom(t_hook *p, t_fract *f);
#endif
