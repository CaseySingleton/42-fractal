/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:08:46 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/05 21:08:47 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libgfx/includes/libgfx.h"
#include <stdio.h>

int				mandelbrot(double real, double imaginary, t_mlx *mlx)
{
	int			iterations;
	double		temp_x;
	double		x;
	double		y;

	real = complex_x(real, mlx->x_offset, mlx->scale);
	imaginary = complex_y(imaginary, mlx->y_offset, mlx->scale);
	x = 0;
	y = 0;
	iterations = -1;
	while (++iterations < mlx->max_iterations)
	{
		if ((x * x) + (y * y) >= 4)
			return (iterations);
		temp_x = (x * x) - (y * y) + real;
		y = 2 * x * y + imaginary;
		x = temp_x;
	}
	return (iterations);
}

int				julia(double x, double y, t_mlx *mlx)
{
	int			iterations;
	double		temp_x;
	double		r;
	double		i;

	x = complex_x(x, mlx->x_offset, mlx->scale);
	y = complex_y(y, mlx->y_offset, mlx->scale);
	iterations = -1;
	while (++iterations < mlx->max_iterations)
	{
		if ((x * x) + (y * y) >= 4)
			return (iterations);
		temp_x = (x * x) - (y * y) + mlx->julia_r;
		y = 2 * x * y + mlx->julia_i;
		x = temp_x;
	}
	return (iterations);
}

int				burning_ship(double real, double imaginary, t_mlx *mlx)
{
	int			iterations;
	double		temp_x;
	double		x;
	double		y;

	real = complex_x(real, mlx->x_offset, mlx->scale);
	imaginary = complex_y(imaginary, mlx->y_offset, mlx->scale);
	x = 0;
	y = 0;
	iterations = -1;
	while (++iterations < mlx->max_iterations)
	{
		if ((x * x) + (y * y) >= 4)
			return (iterations);
		temp_x = (x * x) - (y * y) + real;
		y = fabs(2 * x * y) + imaginary;
		x = fabs(temp_x);
	}
	return (iterations);
}

void			change_fractal(int key, t_mlx *mlx)
{
	if (key == KEY_1)
		mlx->fractal_funciton = &mandelbrot;
	if (key == KEY_2)
		mlx->fractal_funciton = &burning_ship;
	if (key == KEY_3)
		mlx->fractal_funciton = &julia;
}
