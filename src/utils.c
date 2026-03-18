/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:09:28 by akaung            #+#    #+#             */
/*   Updated: 2026/03/18 15:09:28 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_colour	interpolate(t_colour c1, t_colour c2, double t)
{
	t_colour	result;

	result.r = c1.r + (c2.r - c1.r) * t;
	result.g = c1.g + (c2.g - c1.g) * t;
	result.b = c1.b + (c2.b - c1.b) * t;
	return (result);
}

t_colour	hsv_to_rgb(double h, double s, double v)
{
	double		c;
	double		x;
	double		m;
	double		r1;
	double		g1;
	double		b1;
	t_colour		res;

	c = v * s;
	x = c * (1 - fabs(fmod(h / 60.0,2) - 1));
	m = v - c;
	if (h < 60)
		{ r1 = c; g1 = x; b1 = 0; }
	else if (h < 120)
		{ r1 = x; g1 = c; b1 = 0; }
	else if (h < 180)
		{ r1 = 0; g1 = c; b1 = x; }
	else if (h < 240)
		{ r1 = 0; g1 = x; b1 = c; }
	else if (h < 300)
		{ r1 = x; g1 = 0; b1 = c; }
	else
		{ r1 = c; g1 = 0; b1 = x; }
	res.r = (int)((r1 + m) * 255);
	res.g = (int)((g1 + m) * 255);
	res.b = (int)((b1 + m) * 255);
	return (res);
}

int rgb_to_int(t_colour c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}
