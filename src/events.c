#include "../includes/fractol.h"

int	close_window(t_fractol *f)
{
	(void)f;
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_fractol *f)
{
	if (keycode == 65307)
		close_window(f);
	if (keycode == 99)
	{
		f->r_mult = rand() % 256;
		f->g_mult = rand() % 256;
		f->b_mult = rand() % 256;
		draw_mandelbrot(f);
	}
	return (0);
}
