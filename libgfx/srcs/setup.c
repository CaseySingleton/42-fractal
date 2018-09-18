/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 14:39:30 by csinglet          #+#    #+#             */
/*   Updated: 2018/08/08 20:46:59 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libgfx.h"
#include "../../includes/fractol.h"

int			initialize_mlx(t_mlx **mlx)
{
	if (!((*mlx) = (t_mlx *)malloc(sizeof(t_mlx))))
		return (-1);
	if (!((*mlx)->cam = (t_cam *)malloc(sizeof(t_cam))))
		return (-1);
	if (!((*mlx)->img = (t_img *)malloc(sizeof(t_img))))
		return (-1);
	if (!((*mlx)->keys = (t_keys *)malloc(sizeof(t_keys))))
		return (-1);
	(*mlx)->mlx_ptr = mlx_init();
	return (0);
}

void		create_window(t_mlx **mlx)
{
	(*mlx)->cam->win_ptr = mlx_new_window((*mlx)->mlx_ptr, WIN_WIDTH,
		WIN_HEIGHT, WIN_TITLE);
}

void		create_image(t_mlx *mlx)
{
	mlx->img->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx->img->info = (int *)mlx_get_data_addr(mlx->img->img_ptr, &mlx->img->bpp,
		&mlx->img->len, &mlx->img->endian);
}

/*
**	Display an image to the windo
**
**	- Clear window
**	- Get the image to display
**	- Display the image
**	- Destroy the image
*/

void		display_image(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->cam->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->cam->win_ptr,
		mlx->img->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img->img_ptr);
	create_image(mlx);
}

void		create_enviornment(t_mlx **mlx)
{
	if (initialize_mlx(mlx) == -1)
		exit(0);
	(*mlx)->julia_flag = 0;
	(*mlx)->max_iterations = START_ITERATIONS;
	(*mlx)->color_choice = 1;
	create_window(mlx);
}
