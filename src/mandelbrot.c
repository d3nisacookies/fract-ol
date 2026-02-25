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

int	get_color(double smooth_iter, t_fractol *f)
{
	int	r;
	int	g;
	int	b;

	if (smooth_iter >= MAX_ITER)
		return (0x000000);
	r = (int)(smooth_iter * f->r_mult) % 256;
	g = (int)(smooth_iter * f->g_mult) % 256;
	b = (int)(smooth_iter * f->b_mult) % 256;
	return ((r << 16) | (g << 8) | b);
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