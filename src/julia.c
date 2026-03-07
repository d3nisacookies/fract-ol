#include "../includes/fractol.h"

static double julia(double zr, double zi, t_fractol *f)
{
    double tmp;
    int i;

    i = 0;
    while (zr * zr + zi * zi <= 4 && i < MAX_ITER)
    {
        tmp = zr * zr - zi * zi + f->julia_cr;
        zi = 2 * zr * zi + f->julia_ci;
        zr = tmp;
        i++;
    }
    if (i == MAX_ITER)
    {
        return (MAX_ITER);
    }
    return (i + 1 - log(log(sqrt(zr * zr + zi * zi))) / log(2.0));
}

void draw_julia(t_fractol *f)
{
    int     x;
    int     y;
    double  zr;
    double  zi;
    double  smooth;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            zr = f->min_r + (x / (double)WIDTH) * (f->max_r - f->min_r);
            zi = f->max_i - (y / (double)HEIGHT) * (f->max_i - f->min_i);

            smooth = julia(zr, zi, f);
            put_pixel(&f->img, x, y, get_color(smooth, f));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
}