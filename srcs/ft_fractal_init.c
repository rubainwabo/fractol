/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:58:03 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/11 14:01:42 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_fract	*ft_mandelbrot_init(void)
{
	t_fract	*f;

	if (!(f = (t_fract*)malloc(sizeof(*f))))
		return (NULL);
	f->x1 = -2.5;
	f->x2 = 0.6;
	f->y1 = 1.2;
	f->y2 = -1.2;
	return (f);
}

static t_fract	*ft_julia_init(void)
{
	t_fract *f;

	if (!(f = (t_fract*)malloc(sizeof(*f))))
		return (NULL);
	f->x1 = -2.5;
	f->x2 = 0.6;
	f->y1 = 1.2;
	f->y2 = -1.2;
	return (f);
}

static	t_fract	*ft_fract3(void)
{
	t_fract *f;

	if (!(f = (t_fract*)malloc(sizeof(*f))))
		return (NULL);
	f->x1 = -2.5;
	f->x2 = 0.6;
	f->y1 = 1.2;
	f->y2 = -1.2;
	return (f);
}

t_fract	*ft_fractal_init(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot"))
		return (ft_mandelbrot_init());
	else if (!ft_strcmp(str, "Julia"))
		return (ft_julia_init());
	else if (!ft_strcmp(str, "fract_3"))
		return (ft_fract3());
	return (NULL);
}