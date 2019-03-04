/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 23:24:53 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/01 22:07:33 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_mouse(int button, int x, int y, void *param)
{
	t_hook		*reader;

	reader = param;
	if (button == 5)
	{
		reader->fract.zoom += 10;
	//	reader->fract.it_max += 100;
	}
	else if (button == 4)
	{
		reader->fract.zoom -= 10;
	//	reader->fract.it_max -= 20;
	}
	ft_draw_image(reader->mlx_ptr, reader->win_ptr, reader);
	return (0);
}
