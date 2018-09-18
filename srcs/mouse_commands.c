/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 17:32:14 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/17 17:32:15 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			julia_mouse_info(t_mlx *mlx)
{
	mlx->julia_r = mlx->mouse_x * 4 / IMG_WIDTH - 2.0;
	mlx->julia_i = mlx->mouse_y * 4 / IMG_HEIGHT - 2.0;
}

int				mouse_info(int x, int y, t_mlx *mlx)
{
	mlx->mouse_x = x;
	mlx->mouse_y = y;
	return (0);
}

int				mouse_hook(int mouse_button, int x, int y, t_mlx *mlx)
{
	if ((mouse_button == 1 || mouse_button == MOUSE_SCROLL_UP)
		&& mlx->mouse_x >= 0 && mlx->mouse_x <= WIN_WIDTH && mlx->mouse_y >= 0
		&& mlx->mouse_y <= WIN_HEIGHT)
	{
		mlx->scale *= 1.1;
		mlx->x_offset -= ((WIN_WIDTH / 2) - mlx->mouse_x) / mlx->scale;
		mlx->y_offset -= ((WIN_HEIGHT / 2) - mlx->mouse_y) / mlx->scale;
	}
	if (mouse_button == MOUSE_SCROLL_DOWN && mlx->mouse_x >= 0
		&& mlx->mouse_x <= WIN_WIDTH && mlx->mouse_y >= 0
		&& mlx->mouse_y <= WIN_HEIGHT)
	{
		mlx->scale *= 0.9;
		mlx->x_offset -= ((WIN_WIDTH / 2) - mlx->mouse_x) / mlx->scale;
		mlx->y_offset -= ((WIN_HEIGHT / 2) - mlx->mouse_y) / mlx->scale;
	}
	manage_threads(mlx);
	display_image(mlx);
	return (0);
}

void			reset(t_mlx *mlx)
{
	mlx->scale = 1;
	mlx->x_offset = 0;
	mlx->y_offset = 0;
}
