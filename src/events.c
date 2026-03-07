#include "../includes/fractol.h"

int	close_window(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
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
		if (f->is_julia)
		{
			draw_julia(f);
		}
		else 
		{
			draw_mandelbrot(f);
		}
	}
	return (0);
}
