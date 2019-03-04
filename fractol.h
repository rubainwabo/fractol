/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/01 23:10:25 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# define WIDTH 1200
# define HEIGHT 1200
# define RGB(x, y, z) (x | y | z)
# define MAX(x, y, z) ((x >= y) ? ((x >= z) ? x : z) : ((y >= z) ? y : z))
# define MIN(x, y, z) ((x <= y) ? ((x <= z) ? x : z) : ((y <= z) ? y : z))

typedef struct	s_fract
{
	int			it_max;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	int			image_x;
	int			image_y;
	float		zoom_x;
	float		zoom_y;
	float		x;
	float		y;
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	int			i;
	float		tmp;
	int			zoom;
	int			color[1000];
}				t_fract;

typedef struct	s_hook
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_fract		fract;
}				t_hook;

void	ft_draw_image(void *mlx_ptr, void *win_ptr, t_hook *param);
int		ft_get_color(int color1, int color2, double percentage);
int		ft_opti(float x, float y);
int		deal_mouse(int button, int x, int y, void *param);
#endif
