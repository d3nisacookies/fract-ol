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



static t_colour	apply_color_multipliers(t_colour color, t_fractol *f)
{
	color.r = (color.r * f->r_mult) / 256;
	color.g = (color.g * f->g_mult) / 256;
	color.b = (color.b * f->b_mult) / 256;
	return (color);
}

int get_color(double iter, t_fractol *f)
{
	double t;
	double hue, sat, val;
	t_colour color;

	if (iter == MAX_ITER)
		return (BLACK);

	/* normalise iteration count */
	t = iter / MAX_ITER;

	/* hue cycles through spectrum but slower for realistic look */
	hue = 360.0 * sqrt(t);

	/* saturation varies so edges are more washed out */
	sat = 0.5 + 0.5 * t;

	/* value decreases with t for darker interiors */
	val = 1.0 - 0.5 * t;

	color = hsv_to_rgb(hue, sat, val);
	color = apply_color_multipliers(color, f);
	return (rgb_to_int(color));
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