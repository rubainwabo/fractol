/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 23:24:53 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 23:11:53 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_mouse(int button, int x, int y, void *param)
{
	t_hook		*reader;

	reader = param;
	if (button == 1)
	{
		reader->mouse_x = x;
		reader->mouse_y = y;
	}
	else if (button == 5)
	{
		reader->zoom = 2.01;
		ft_zoom(reader, reader->fract);
	}
	else if (button == 4)
	{
		reader->zoom = 1 / 2.01;
		ft_zoom(reader, reader->fract);
	}
	ft_draw_image(reader, reader->fract);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_hook		*reader;

	reader = param;
	x = x + 0;
	y = y + 0;
	/*if (!ft_strcmp("Julia", reader->w_fract))
	{
		reader->fract->c_r -= 0.1;
		reader->fract->c_i -= 0.01;
	}*/
	//printf("x = %d\n y = %d\n", x, y);
	return (0);
}

static int		deal_key_sec(int key, void *param)
{
	if (key == 53)
	{
		(void)param;
		exit(0);
	}
	return (0);
}

int		deal_key(int key, void *param)
{
	t_hook		*reader;

	reader = param;
	if (key == 124)
		reader->move_x -= (0.2 * (reader->fract->x2 - reader->fract->x1) / 3.1);
	else if (key == 123)
		reader->move_x += (0.2 * (reader->fract->x2 - reader->fract->x1) / 3.1);
	else if (key == 125)
		reader->move_y += (0.2 * (reader->fract->y2 - reader->fract->y1) / -2.4);
	else if (key == 126)
		reader->move_y -= (0.2 * (reader->fract->y2 - reader->fract->y1) / -2.4);
	else if (key == 69)
		reader->fract->it_max += 15;
	else if (key == 78)
		reader->fract->it_max -= 15;
	else
		deal_key_sec(key, param);
	ft_draw_image(reader, reader->fract);
	return (0);
}
