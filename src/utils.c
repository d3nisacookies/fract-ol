#include "../includes/fractol.h"

/* linear interpolation between two colours (unused now but kept) */
t_colour interpolate(t_colour c1, t_colour c2, double t)
{
	t_colour result;

	result.r = c1.r + (c2.r - c1.r) * t;
	result.g = c1.g + (c2.g - c1.g) * t;
	result.b = c1.b + (c2.b - c1.b) * t;
	return (result);
}

/* convert HSV colour to RGB (h in [0,360], s,v in [0,1]) */
t_colour hsv_to_rgb(double h, double s, double v)
{
	double c = v * s;
	double x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	double m = v - c;
	double r1, g1, b1;

	if (h < 60)        { r1 = c; g1 = x; b1 = 0; }
	else if (h < 120)  { r1 = x; g1 = c; b1 = 0; }
	else if (h < 180)  { r1 = 0; g1 = c; b1 = x; }
	else if (h < 240)  { r1 = 0; g1 = x; b1 = c; }
	else if (h < 300)  { r1 = x; g1 = 0; b1 = c; }
	else               { r1 = c; g1 = 0; b1 = x; }

	t_colour res;
	res.r = (int)((r1 + m) * 255);
	res.g = (int)((g1 + m) * 255);
	res.b = (int)((b1 + m) * 255);
	return (res);
}

int rgb_to_int(t_colour c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}
