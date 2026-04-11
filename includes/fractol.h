/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:36:24 by akaung            #+#    #+#             */
/*   Updated: 2026/03/18 15:38:30 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <time.h>

# define WIDTH 800
# define HEIGHT 600

/* colors */
# define BLACK 0x000000
# define WHITE 0xFFFFFF

/* mouse */
# define ZOOM_IN 4
# define ZOOM_OUT 5

/* defines*/
# define MAX_ITER 100

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	t_img	img;

	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	julia_cr;
	double	julia_ci;

	int		r_mult;
	int		g_mult;
	int		b_mult;
	int		is_julia;
}			t_fractol;

typedef struct s_colour
{
	int		r;
	int		g;
	int		b;
}			t_colour;

/* init */
void		init_fractol(t_fractol *f);

/* draw */
void		draw_screen(t_fractol *f);
void		put_pixel(t_img *img, int x, int y, int color);

/* events */
int			key_hook(int keycode, t_fractol *f);
int			close_window(t_fractol *f);

/* mouse */
int			mouse_hook(int button, int x, int y, t_fractol *f);

/* mandelbrot */
void		draw_mandelbrot(t_fractol *f);

/* julia */
void		draw_julia(t_fractol *f);
int			get_color(double smooth_iter, t_fractol *f);

/* utils */
t_colour	interpolate(t_colour c1, t_colour c2, double t);
int			rgb_to_int(t_colour c);

/* color helpers */
t_colour	hsv_to_rgb(double h, double s, double v);

#endif
