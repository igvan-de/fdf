/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 12:05:50 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/24 20:06:18 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_window(t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx->image = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->placement = mlx_put_image_to_window(mlx->mlx_ptr, mlx->window, mlx->image, 650, 450);
	test(mlx);
	return (0);
}



























	// mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
	//mlx->image = mlx_pixel_put(mlx->mlx_ptr, mlx->window, 50 + mlx->x, 50 + mlx->y, yellow);