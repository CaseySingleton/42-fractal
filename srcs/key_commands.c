/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:52:02 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/05 17:52:04 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libgfx/includes/libgfx.h"
#include "../includes/fractol.h"
#include "../includes/win_keys.h"

int				use_key(int key, t_mlx *mlx)
{
	if (key == 53)
		exit(0);
	if (key == KEY_PLUS)
		mlx->scale *= 1.1;
	if (key == KEY_MINUS)
		mlx->scale *= 0.9;
	if (key == KEY_DOWN)
		if (mlx->max_iterations - 16 > 0)
			mlx->max_iterations -= 16;
	if (key == KEY_UP)
		if (mlx->max_iterations + 16 < 256)
			mlx->max_iterations += 16;
	if (key == 15)
		reset(mlx);
	change_color(mlx, key);
	change_fractal(key, mlx);
	manage_threads(mlx);
	display_image(mlx);
	return (0);
}

int				key_pressed(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->keys->w = 1;
	if (key == KEY_A)
		mlx->keys->a = 1;
	if (key == KEY_S)
		mlx->keys->s = 1;
	if (key == KEY_D)
		mlx->keys->d = 1;
	if (key == KEY_SPACE)
		mlx->keys->space = 1;
	use_key(key, mlx);
	return (0);
}

int				key_released(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->keys->w = 0;
	if (key == KEY_A)
		mlx->keys->a = 0;
	if (key == KEY_S)
		mlx->keys->s = 0;
	if (key == KEY_D)
		mlx->keys->d = 0;
	if (key == KEY_SPACE)
		mlx->keys->space = 0;
	return (0);
}

int				key_loop(t_mlx *mlx)
{
	if (mlx->keys->w == 1 || mlx->keys->a == 1 || mlx->keys->s == 1
		|| mlx->keys->d == 1 || mlx->keys->space == 1)
		mlx->keys->change = 1;
	if (mlx->keys->plus == 1)
		mlx->scale -= 1;
	if (mlx->keys->minus == 1)
		mlx->scale += 1;
	if (mlx->keys->w == 1)
		mlx->y_offset -= 50 / mlx->scale;
	if (mlx->keys->s == 1)
		mlx->y_offset += 50 / mlx->scale;
	if (mlx->keys->a == 1)
		mlx->x_offset -= 50 / mlx->scale;
	if (mlx->keys->d == 1)
		mlx->x_offset += 50 / mlx->scale;
	if (mlx->keys->space == 1)
		julia_mouse_info(mlx);
	if (mlx->keys->change == 1 || (mlx->keys->space == 1
		&& mlx->fractal_funciton == julia))
	{
		manage_threads(mlx);
		display_image(mlx);
		mlx->keys->change = 0;
	}
	return (0);
}

void			set_hooks(t_mlx *mlx)
{
	mlx_do_key_autorepeatoff(mlx->mlx_ptr);
	mlx_hook(mlx->cam->win_ptr, 3, 0, key_released, mlx);
	mlx_hook(mlx->cam->win_ptr, 2, 0, key_pressed, mlx);
	mlx_hook(mlx->cam->win_ptr, 6, 0, mouse_info, mlx);
}
