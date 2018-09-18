/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 19:48:02 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/13 19:48:03 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include "../libgfx/includes/libgfx.h"
#include <stdio.h>

/*
**	To draw a fractal:
**	  - Iterate through all pixels of image
**		- For each pixel
**		  - "Flatten" (x, y) value of pixel to a scale
**		  - Put values into fractal_func()
**		  - Color pixel with using return from fractal_func()
*/

void			*draw_fractal(void *thread_arg)
{
	t_thread		*t;
	int				y;
	int				x;
	int				color;
	int				i;

	t = (t_thread *)thread_arg;
	y = t->thread_id;
	while (y < IMG_HEIGHT)
	{
		x = -1;
		while (++x < IMG_WIDTH)
		{
			i = t->mlx->fractal_funciton((double)x, (double)y, t->mlx);
			color = ((double)i /
				(double)t->mlx->max_iterations) * 100;
			color = color_effects(t->mlx, color);
			if (i != t->mlx->max_iterations && i > 1)
				t->mlx->img->info[y * IMG_WIDTH + x] = color * 18;
		}
		y += NUM_THREADS;
	}
	return (NULL);
}

int				manage_threads(t_mlx *mlx)
{
	int			i;
	pthread_t	threads[NUM_THREADS];
	t_thread	thread_structs[NUM_THREADS];

	i = -1;
	while (++i < NUM_THREADS)
	{
		thread_structs[i].mlx = mlx;
		thread_structs[i].thread_id = i;
		pthread_create(&threads[i], NULL, draw_fractal, &thread_structs[i]);
	}
	i = -1;
	while (++i < NUM_THREADS)
		pthread_join(threads[i], NULL);
	return (0);
}

/*
**	get_y and get_x return the (x , y) position on a complex plane given
**	a pixels numerical position.
**
**	remember that pixels start at 0, therefore 0 is the first position for
**	x and y so for a resolution of 1200x1600 the total number of pixels is
**	1,920,000 but the last pixel location is represented by 1,919,999
*/

double			complex_y(double y, double offset, double scale)
{
	double		new_y;

	new_y = ((4.0 * y / IMG_HEIGHT - 2.0) / scale)
		+ (offset / IMG_WIDTH);
	return (new_y);
}

double			complex_x(double x, double offset, double scale)
{
	double		new_x;

	new_x = ((4.0 * x / IMG_WIDTH - 2.0) / scale)
		+ (offset / IMG_WIDTH);
	return (new_x);
}
