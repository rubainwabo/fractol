/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 14:01:42 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# define WIDTH 1200
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
	double		tmp;
}				t_fract;
typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;
typedef struct	s_event
{
	int			mouse_x;
	int			mouse_y;
	double		move_x;
	double		move_y;
	double		zoom;
}				t_event;
typedef struct	s_hook
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			mouse_x;
	int			mouse_y;
	t_event		e;
	t_fract		*fract;
}				t_hook;

t_hook	*ft_check_error(int ac, char **argv);
t_fract	*ft_fractal_init(char *str);
void	ft_draw_image(t_hook *param, t_fract *f);
void	mlx_put_pixel_img(char *image_str, int x, int y, int color);
void	ft_mandelbrot(char *image_str, t_color *c, t_hook *p, t_fract *f);
int		ft_get_color(int color1, int color2, double percentage);
int		ft_opti(double x, double y);
int		deal_mouse(int button, int x, int y, void *param);
int		deal_key(int key, void *param);
t_color	*ft_init(void);
void	ft_get_rgb_smooth(t_color *c, int i, int t_max);
void	ft_zoom_displace(t_hook *par);
void	ft_hsv2rgb(t_color *c, double h, double s, double v);
void	ft_zoom(t_hook *p, t_fract *f);
#endif
