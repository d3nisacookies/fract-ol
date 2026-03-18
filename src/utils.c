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

static t_colour	rgb_low(double h, double c, double x, double m)
{
	t_colour	res;

	if (h < 60)
	{
		res.r = (int)((c + m) * 255);
		res.g = (int)((x + m) * 255);
		res.b = (int)(m * 255);
	}
	else if (h < 120)
	{
		res.r = (int)((x + m) * 255);
		res.g = (int)((c + m) * 255);
		res.b = (int)(m * 255);
	}
	else
	{
		res.r = (int)(m * 255);
		res.g = (int)((c + m) * 255);
		res.b = (int)((x + m) * 255);
	}
	return (res);
}

static t_colour	rgb_high(double h, double c, double x, double m)
{
	t_colour	res;

	if (h < 240)
	{
		res.r = (int)(m * 255);
		res.g = (int)((x + m) * 255);
		res.b = (int)((c + m) * 255);
	}
	else if (h < 300)
	{
		res.r = (int)((x + m) * 255);
		res.g = (int)(m * 255);
		res.b = (int)((c + m) * 255);
	}
	else
	{
		res.r = (int)((c + m) * 255);
		res.g = (int)(m * 255);
		res.b = (int)((x + m) * 255);
	}
	return (res);
}

t_colour	hsv_to_rgb(double h, double s, double v)
{
	double		c;
	double		x;
	double		m;

	c = v * s;
	x = c * (1 - fabs(fmod(h / 60.0, 2) - 1));
	m = v - c;
	if (h < 180)
		return (rgb_low(h, c, x, m));
	return (rgb_high(h, c, x, m));
}

int	rgb_to_int(t_colour c)
{
	return ((c.r << 16) | (c.g << 8) | c.b);
}
