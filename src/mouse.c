#include "../includes/fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *f)
{
	double	zoom;
	double	cr;
	double	ci;

	if (button == ZOOM_IN)
		zoom = 0.9;
	else if (button == ZOOM_OUT)
		zoom = 1.1;
	else
		return (0);
	cr = f->min_r + (x / (double)WIDTH) * (f->max_r - f->min_r);
	ci = f->max_i - (y / (double)HEIGHT) * (f->max_i - f->min_i);
	f->min_r = cr + (f->min_r - cr) * zoom;
	f->max_r = cr + (f->max_r - cr) * zoom;
	f->min_i = ci + (f->min_i - ci) * zoom;
	f->max_i = ci + (f->max_i - ci) * zoom;
	if (f->is_julia)
	{
		draw_julia(f);
	}
	else 
	{
		draw_mandelbrot(f);
	}
	return (0);
}
