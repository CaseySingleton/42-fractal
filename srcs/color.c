/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:04:47 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/06 14:06:34 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			change_color(t_mlx *mlx, int key)
{
	if (key == KEY_Q)
	{
		if (mlx->color_choice - 1 < 1)
			mlx->color_choice = 6;
		else
			mlx->color_choice--;
	}
	if (key == KEY_E)
	{
		if (mlx->color_choice + 1 > 6)
			mlx->color_choice = 1;
		else
			mlx->color_choice++;
	}
}

int				get_color(int r, int g, int b)
{
	int			color;

	color = (r * 256 * 256) + (g * 256) + (b);
	return (color);
}

int				color_effects(t_mlx *mlx, int color)
{
	if (mlx->color_choice == 1)
		color = get_color((color % 10), 0, color);
	if (mlx->color_choice == 2)
		color = get_color(color / 3, sin(color), color * 2.2);
	if (mlx->color_choice == 3)
		color = get_color(color * 0.3, color * 0.66, color);
	if (mlx->color_choice == 4)
		color = get_color(color % 22, color / 1.2, color * 2);
	if (mlx->color_choice == 5)
		color = get_color(0, color, color * 2);
	if (mlx->color_choice == 6)
		color = get_color(color, color, color);
	return (color);
}

/*
**	get_color_gradient()
**	Returns an array of 101 hexadecimal numbers between two numbers
**	Need to replace the number 100 with a defined size
*/

int				*get_color_gradient(int color1, int color2)
{
	int		i;
	int		step;
	int		*gradient;

	if (color1 < color2)
		return (get_color_gradient(color2, color1));
	if (!(gradient = (int *)malloc(sizeof(int) * 100 + 1)))
		return (NULL);
	step = (color1 - color2) / 100;
	i = -1;
	while (++i < 100 + 1)
	{
		gradient[i] = color1;
		color1 -= step;
	}
	return (gradient);
}
