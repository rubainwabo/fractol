/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:18:44 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 23:41:19 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ft_opti(double x, double y)
{
	//the function returns 0 if x and y are not in the set and 1 if they are
	double x_square;
	double y_square;

	x_square = x * x;
	y_square = y * y;
	if (x_square + 2 * x + 1 + y_square <= 1 / 16)
		return (0);
	return (1);
}
