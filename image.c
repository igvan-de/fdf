/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 12:05:50 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/20 17:45:38 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_window(t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx->image = mlx_new_image(mlx->mlx_ptr, 10, 50);
	// mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
	// mlx->image = mlx_pixel_put(mlx->mlx_ptr, mlx->window, 50 + mlx->x, 50 + mlx->y, yellow);
	return (0);
}
