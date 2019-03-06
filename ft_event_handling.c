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

#include "fractol.h"

int		deal_mouse(int button, int x, int y, void *param)
{
	t_hook		*reader;

	reader = param;
	if (button == 5)
	{
		reader->e.zoom += 0.1;
		reader->fract.it_max += 1;
	}
	else if (button == 4)
	{
		reader->e.zoom -= 0.1;
		reader->fract.it_max -= 1;
	}
	reader->e.mouse_x = x;
	reader->e.mouse_y = y;
	ft_draw_image(reader->mlx_ptr, reader->win_ptr, reader);
	return (0);
}

int		deal_key(int key, void *param)
{
	t_hook		*reader;

	reader = param;
	if (key == 13)
		reader->e.move_y -= 5;
	if (key == 1)
		reader->e.move_y += 5;
	if (key == 0 || key == 2)
		reader->e.move_x += key * 5 - 5;
	ft_draw_image(reader->mlx_ptr, reader->win_ptr, reader);
	return (0);
}
