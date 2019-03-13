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

int		deal_mouse(int button, int x, int y, t_fract *f)
{
	if (button == 1)
	{
		f->mouse_x = x;
		f->mouse_y = y;
	}
	else if (button == 5)
	{
		f->zoom = 2.01;
		ft_zoom(f);
	}
	else if (button == 4)
	{
		f->zoom = 1 / 2.01;
		ft_zoom(f);
	}
	ft_draw_image(f);
	return (0);
}

static int		deal_key_sec(int key, t_fract *f)
{
	if (key == 53)
	{
		(void)f;
		exit(0);
	}
	return (0);
}

int		deal_key(int key, t_fract *f)
{
	if (key == 124)
		f->move_x -= (0.2 * (f->x2 - f->x1) / 3.1);
	else if (key == 123)
		f->move_x += (0.2 * (f->x2 - f->x1) / 3.1);
	else if (key == 125)
		f->move_y += (0.2 * (f->y2 - f->y1) / -2.4);
	else if (key == 126)
		f->move_y -= (0.2 * (f->y2 - f->y1) / -2.4);
	else if (key == 69)
		f->it_max += 15;
	else if (key == 78)
		f->it_max -= 15;
	else
		deal_key_sec(key, f);
	ft_draw_image(f);
	return (0);
}
