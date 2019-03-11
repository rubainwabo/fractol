/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 23:24:53 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/06 02:54:10 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		deal_mouse(int button, int x, int y, void *param)
{
	t_hook		*reader;

	reader = param;
	if (button == 1)
	{
		reader->e.mouse_x = x;
		reader->e.mouse_y = y;
	}
	else if (button == 4)
	{
		reader->e.zoom = 2.01;
		ft_zoom(reader, reader->fract);
	}
	else if (button == 5)
	{
		reader->e.zoom = 1 / 2.01;
		ft_zoom(reader, reader->fract);
	}
	ft_draw_image(reader, reader->fract);
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
		reader->e.move_x -= (0.2 * (reader->fract->x2 - reader->fract->x1) / 3.1);
	else if (key == 123)
		reader->e.move_x += (0.2 * (reader->fract->x2 - reader->fract->x1) / 3.1);
	else if (key == 125)
		reader->e.move_y += (0.2 * (reader->fract->y2 - reader->fract->y1) / -2.4);
	else if (key == 126)
		reader->e.move_y -= (0.2 * (reader->fract->y2 - reader->fract->y1) / -2.4);
	else if (key == 69)
		reader->fract->it_max += 15;
	else if (key == 78)
		reader->fract->it_max -= 15;
	else
		deal_key_sec(key, param);
	ft_draw_image(reader, reader->fract);
	return (0);
}
