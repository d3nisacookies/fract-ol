/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaung <akaung@student.42.sg>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 15:05:13 by akaung            #+#    #+#             */
/*   Updated: 2026/03/18 15:05:14 by akaung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_usage(void)
{
	write(2, "Usage: ./fractol mandelbrot\n", 29);
	write(2, "Usage: ./fractol julia <cr> <ci>\n", 34);
}

static int	handle_julia(char **av, int ac, t_fractol *f)
{
	if (ac != 4)
		return (print_usage(), 1);
	f->is_julia = 1;
	f->julia_cr = atof(av[2]);
	f->julia_ci = atof(av[3]);
	draw_julia(f);
	return (0);
}

static int	handle_fractol(char **av, int ac, t_fractol *f)
{
	srand(time(NULL));
	init_fractol(f);
	if (!strncmp(av[1], "julia", 5))
		return (handle_julia(av, ac, f));
	if (!strncmp(av[1], "mandelbrot", 10))
	{
		f->is_julia = 0;
		draw_mandelbrot(f);
		return (0);
	}
	return (print_usage(), 1);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
		return (print_usage(), 1);
	if (handle_fractol(av, ac, &f))
		return (1);
	mlx_key_hook(f.win, key_hook, &f);
	mlx_mouse_hook(f.win, mouse_hook, &f);
	mlx_hook(f.win, 17, 0, close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
