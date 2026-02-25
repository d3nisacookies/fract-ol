#include "../includes/fractol.h"
#include <time.h>

void	init_fractol(t_fractol *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line_len,
			&f->img.endian);
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
	srand(time(NULL));
	f->r_mult = rand() % 256;
	f->g_mult = rand() % 256;
	f->b_mult = rand() % 256;
}
