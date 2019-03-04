/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_RGBtoHSV.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 04:41:06 by rkamegne          #+#    #+#             */
/*   Updated: 2019/02/27 04:57:17 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol"

void	ft_RGBtoHSV(int r, int g, int b, int *h, int *s, int *v)
{
	int		min;
	int		max;
	int		delta;

	min = MIN(r, g, b);
	max = MAX(r, g, b);
	*v = max;
	delta = max - min;
	if (max != 0)
		*s = delta / max;
	else
	{
		//r = g = b = 0  s = 0, v is undefined
		*s = 0;
		*h = -1;
		return ;
	}
	if (r == max)
		*h = (g - b) / delta; // between yellow and magenta
	else if (g == max)
		*h = 2 + (b - r) / delta; // between cyan and yellow
	else
		*h = 4 + (r - g) / delta; // between magenta and cyan
	*h *= 60;					//degrees
	if (*h < 0)
		*h += 360;
}
