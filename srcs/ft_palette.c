/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:32:57 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/15 15:34:47 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		ft_get_color(int color1, int color2, double percentage)
{
	int			green;
	int			blue;
	int			red;

	red = get_light((color1 >> 16) & 0xFF, (color2 >> 16) & 0xFF, percentage);
	green = get_light((color1 >> 8) & 0xFF, (color2 >> 8) & 0xFF, percentage);
	blue = get_light(color1 & 0xFF, color2 & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

static void		colour_circle(t_thread *array)
{
	array->colour[0] = 0xffd300;
	array->colour[1] = 0xfc4856;
	array->colour[2] = 0xf3008a;
	array->colour[3] = 0x3bf600;
	array->colour[4] = 0x0435a8;
	array->colour[5] = 0x1ec4d8;
	array->colour[6] = 0xffe4e1;
	array->colour[7] = 0x33deff;
	array->colour[8] = 0xb03600;
	array->colour[9] = 0x88dd88;
	array->colour[10] = 0xba55d3;
	array->colour[11] = 0xeee9e9;
}

int				ft_color_fractal(int x, int y)
{
	t_thread	array;
	float		angle;
	float		r;

	colour_circle(&array);
	x -= (WIDTH - 100);
	y -= (HEIGHT - 100);
	r = sqrt(pow((float)x / 100, 2) + pow((float)y / 100, 2));
	if (r > 1)
		return (0);
	angle = acos((float)(x / r) / 100);
	if (y < 0)
		angle = 2 * PI - angle;
	if ((int)(angle / (PI / 6)) < 0 || (int)(angle / (PI / 6)) > 11)
		return (0);
	return (ft_get_color(array.colour[(int)(angle / (PI / 6))], 0xffffff,
				1 - r));
}

void			ft_draw_circle(void *mlx_ptr, void *win_ptr, int r)
{
	t_thread	array;
	int			count;
	float		pixel;
	float		angle;

	colour_circle(&array);
	angle = 0;
	count = 0;
	while (angle <= 6.28)
	{
		count = (int)(angle / (PI / 6));
		pixel = -1;
		while (++pixel <= r)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, (int)((WIDTH - 100) + pixel *
						cos(angle)), (int)((HEIGHT - 100) + pixel * sin(angle)),
					ft_get_color(array.colour[count], 0xffffff, 1 - pixel / r));
		}
		angle += 0.005;
	}
}
