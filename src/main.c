#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac == 2)
	{
		init_fractol(&f);
		draw_mandelbrot(&f);
		mlx_key_hook(f.win, key_hook, &f);
		mlx_mouse_hook(f.win, mouse_hook, &f);
		mlx_hook(f.win, 17, 0, close_window, &f);
		mlx_loop(f.mlx);
	}
	write(1, "error", 5);
}
