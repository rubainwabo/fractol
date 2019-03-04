#include "fractol.h"

t_color		*ft_init(void)
{
	t_color	*c;

	if (!(c = (t_color*)malloc(sizeof(*c))))
		return (NULL);
	c->r = 0;
	c->g = 0;
	c->b = 0;
	return (c);
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
	if (i == 0)
	{
		c->r = v;
		c->g = n;
		c->b = l;
	}
	if (i == 1)
	{
		c->r = m;
		c->g = v;
		c->b = l;
	}
	if (i == 2)
	{
		c->r = l;
		c->g = v;
		c->b = n;
	}
	if (i == 3)
	{
		c->r = l;
		c->g = m;
		c->b = v;
	}
	if (i == 4)
	{
		c->r = n;
		c->g = l;
		c->b = v;
	}
	if (i == 5)
	{
		c->r = v;
		c->g = l;
		c->b = m;
	}
}