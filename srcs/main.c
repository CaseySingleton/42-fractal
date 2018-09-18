/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:01:10 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/08 20:43:33 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libgfx/includes/libgfx.h"

void			cam_init(t_mlx *mlx)
{
	mlx->scale = 1;
	mlx->x_offset = 0;
	mlx->y_offset = 0;
}

static void		usage(void)
{
	ft_putstr("Execute with ./fractol (fractal name)\n");
	ft_putstr("Fractals: mandelbrot, julia, bship\n");
	exit(1);
}

void			get_fractol(char *arg, t_mlx *mlx)
{
	if (ft_strcmp(arg, "mandelbrot") == 0)
		mlx->fractal_funciton = &mandelbrot;
	if (ft_strcmp(arg, "bship") == 0)
		mlx->fractal_funciton = &burning_ship;
	if (ft_strcmp(arg, "julia") == 0)
		mlx->fractal_funciton = &julia;
	if (ft_strcmp(arg, "mandelbrot") != 0
		&& ft_strcmp(arg, "bship") != 0
		&& ft_strcmp(arg, "julia") != 0)
		usage();
}

int				main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc == 2)
	{
		create_enviornment(&mlx);
		cam_init(mlx);
		set_hooks(mlx);
		get_fractol(argv[1], mlx);
		create_image(mlx);
		manage_threads(mlx);
		display_image(mlx);
		mlx_mouse_hook(mlx->cam->win_ptr, mouse_hook, mlx);
		mlx_loop_hook(mlx->mlx_ptr, key_loop, mlx);
		mlx_loop(mlx->mlx_ptr);
	}
	usage();
	return (0);
}
