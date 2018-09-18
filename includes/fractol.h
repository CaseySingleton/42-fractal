/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 21:04:18 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/05 21:04:20 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libgfx/includes/libgfx.h"
# include <pthread.h>

# define START_ITERATIONS 32
# define NUM_THREADS 8

typedef struct		s_thread
{
	int				thread_id;
	t_mlx			*mlx;
}					t_thread;

int					mandelbrot(double real, double imaginary, t_mlx *mlx);
int					julia(double real, double imaginary, t_mlx *mlx);
int					burning_ship(double real, double imaginary, t_mlx *mlx);
void				change_fractal(int key, t_mlx *mlx);

int					manage_threads(t_mlx *mlx);
void				*draw_fractal(void *thread_arg);
double				complex_y(double y, double offset, double scale);
double				complex_x(double x, double offset, double scale);

void				change_color(t_mlx *mlx, int key);
int					get_color(int r, int g, int b);
int					color_effects(t_mlx *mlx, int color);
int					*get_color_gradient(int color1, int color2);

int					use_key(int key, t_mlx *mlx);
int					key_pressed(int key, t_mlx *mlx);
int					key_released(int key, t_mlx *mlx);
int					key_loop(t_mlx *mlx);
void				set_hooks(t_mlx *mlx);

void				julia_mouse_info(t_mlx *mlx);
int					mouse_info(int x, int y, t_mlx *mlx);
int					mouse_hook(int mouse_button, int x, int y, t_mlx *mlx);
void				reset(t_mlx *mlx);

#endif
