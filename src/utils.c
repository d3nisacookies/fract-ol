#include "../includes/fractol.h"

t_colour interpolate(t_colour c1, t_colour c2, double t)
{
	t_colour result;

	result.r = c1.r + (c2.r - c1.r) * t;
	result.g = c1.g + (c2.g - c1.g) * t;
	result.b = c1.b + (c2.b - c1.b) * t;
	return (result);
}

int rgb_to_int(t_colour c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}
