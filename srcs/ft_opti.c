/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:18:44 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/01 23:18:59 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_opti(double x, double y)
{
	//the function returns 0 if x and y are not in the set and 1 if they are
	float x_square;
	float y_square;
	//float p;

	x_square = x * x;
	y_square = y * y;
	//p = sqrt(x_square - 0.4375 + y_square);
	if (/*(x <= p - (2 * p * p) + 0.25) ||*/ (x_square + 2 * x + 1 + y_square <=
				0.0625))
		return (0);
	return (1);
}
