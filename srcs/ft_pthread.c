/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pthread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkamegne <rkamegne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:19:37 by rkamegne          #+#    #+#             */
/*   Updated: 2019/03/17 13:10:59 by rkamegne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_thread(t_fract *fract, t_thread data[], int n)
{
	int		i;

	data[0] = (t_thread){.x_start = 0, .y_start = 0, .y_end = HEIGHT,
		.x_end = W_IMG / n, .f = fract};
	i = 0;
	while (++i < n)
	{
		data[i] = (t_thread){.x_start = data[i - 1].x_end, .y_start = 0,
			.y_end = HEIGHT, .x_end = (i + 1) * W_IMG / n, .f = fract};
	}
}

void	launch_threads(t_fract *fract, int n)
{
	pthread_t		ids[n];
	t_thread		data[n];
	pthread_attr_t	attr;
	int				i;

	pthread_attr_init(&attr);
	init_thread(fract, data, n);
	i = -1;
	while (++i < n)
	{
		if (pthread_create(&(ids[i]), &attr, fract->thread, &data[i]) != 0)
		{
			perror("Can't create the thread\n");
			exit(0);
		}
	}
	i = -1;
	while (++i < n)
	{
		if (pthread_join(ids[i], NULL) != 0)
		{
			perror("Can't join thread\n");
			exit(0);
		}
	}
}
