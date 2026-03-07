/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:47:19 by akaung            #+#    #+#             */
/*   Updated: 2026/02/16 17:30:54 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	double	tmp;
	double	i;

	zr = 0;
	zi = 0;
	i = 0;
	while (zr * zr + zi * zi + i < MAX_ITER)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		i++;
	}
	if (i == MAX_ITER)
		return (MAX_ITER);
	return (i + 1 - log(log(sqrt(zr * zr + zi * zi))) / log(2.0));
}

static t_colour	get_gradient_colors(double t, t_colour *c1, t_colour *c2)
{
	if (t < 0.25)
	{
		*c1 = (t_colour){50, 50, 150};
		*c2 = (t_colour){0, 200, 255};
		return (interpolate(*c1, *c2, t / 0.25));
	}
	else if (t < 0.5)
	{
		*c1 = (t_colour){0, 200, 255};
		*c2 = (t_colour){150, 255, 150};
		return (interpolate(*c1, *c2, (t - 0.25) / 0.25));
	}
	else if (t < 0.75)
	{
		*c1 = (t_colour){150, 255, 150};
		*c2 = (t_colour){255, 200, 100};
		return (interpolate(*c1, *c2, (t - 0.5) / 0.25));
	}
	else
	{
		*c1 = (t_colour){255, 200, 100};
		*c2 = (t_colour){255, 255, 255};
		return (interpolate(*c1, *c2, (t - 0.75) / 0.25));
	}
}

static t_colour	apply_color_multipliers(t_colour color, t_fractol *f)
{
	color.r = (color.r * f->r_mult) / 256;
	color.g = (color.g * f->g_mult) / 256;
	color.b = (color.b * f->b_mult) / 256;
	return (color);
}

int get_color(double iter, t_fractol *f)
{
    double      t;
    t_colour     c1;
    t_colour     c2;
    t_colour     final;

    if (iter == MAX_ITER)
        return (0x000000);

    t = iter / MAX_ITER;
    final = get_gradient_colors(t, &c1, &c2);
    final = apply_color_multipliers(final, f);
    
    return (rgb_to_int(final));
}

void	draw_mandelbrot(t_fractol *f)
{
	int x;
	int y;
	double cr;
	double ci;
	double smooth;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = f->min_r + (x / (double)WIDTH) * (f->max_r - f->min_r);
			ci = f->max_i - (y / (double)HEIGHT) * (f->max_i - f->min_i);

			smooth = mandelbrot(cr, ci);
			put_pixel(&f->img, x, y, get_color(smooth, f));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}