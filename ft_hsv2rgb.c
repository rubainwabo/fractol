#include "fractol.h"

t_color	*ft_init(void)
{
	t_color	*c;

	if (!(c = (t_color*)malloc(sizeof(*c))))
		return (NULL);
	c->r = 0;
	c->g = 0;
	c->b = 0;
	return (c);
}

void	ft_get_rgb_smooth(t_color *c, int i, int i_max)
{
	double	t;

	t = (double)i / (double)i_max;
	c->r = (int)(9 * (1 - t) * t * t * t * 255);
	c->g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	c->b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
}

void	ft_hsv2rgb(t_color *c, double h, double s, double v)
{
	long	i;
	double	hh;
	double	f;
	double	l;
	double	m;
	double	n;

	if (s <= 0.0)
	{
		c->r = v;
		c->g = v;
		c->b = v;
		return ;
	}
	hh = h;
	if (hh >= 360.0)
		hh = 0.0;
	hh /= 60.0;
	i = (long)hh;
	f = hh - i;
	l = v * (1 - s);
	m = v * (1 - (f * s));
	n = v * (1 - ((1 - f) * s));
	//printf("l = %f, m = %f, n = %f\n", l, m, n);
	if (i == 0)
	{
		c->r = (int)v;
		c->g = (int)n;
		c->b = (int)l;
	}
	if (i == 1)
	{
		c->r = (int)m;
		c->g = (int)v;
		c->b = (int)l;
	}
	if (i == 2)
	{
		c->r = (int)l;
		c->g = (int)v;
		c->b = (int)n;
	}
	if (i == 3)
	{
		c->r = (int)l;
		c->g = (int)m;
		c->b = (int)v;
	}
	if (i == 4)
	{
		c->r = (int)n;
		c->g = (int)l;
		c->b = (int)v;
	}
	if (i == 5)
	{
		c->r = (int)v;
		c->g = (int)l;
		c->b = (int)m;
	}
}
