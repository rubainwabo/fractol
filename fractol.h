/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/06 02:39:31 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include "../minilibx/mlx.h"
# define WIDTH 1200
# define HEIGHT 600
# define MAX(x, y, z) ((x >= y) ? ((x >= z) ? x : z) : ((y >= z) ? y : z))
# define MIN(x, y, z) ((x <= y) ? ((x <= z) ? x : z) : ((y <= z) ? y : z))

typedef struct	s_fract
{
	int			it_max;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		x;
	float		y;
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	int			i;
	float		tmp;
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
	float		move_x;
	float		move_y;
	float		zoom;
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

void	ft_draw_image(void *mlx_ptr, void *win_ptr, t_hook *param, t_fract *f);
int		ft_get_color(int color1, int color2, double percentage);
int		ft_opti(float x, float y);
int		deal_mouse(int button, int x, int y, void *param);
int		deal_key(int key, void *param);
t_color	*ft_init(void);
void	ft_get_rgb_smooth(t_color *c, int i, int t_max);
void	ft_zoom_displace(t_hook *par);
void	ft_hsv2rgb(t_color *c, double h, double s, double v);
void	ft_zoom(t_hook *p, t_fract *f);
#endif
