/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 12:05:50 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/20 17:00:48 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		image_window(t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	// mlx->image = mlx_new_image(mlx->mlx_ptr, 10, 50);
	mlx->image = mlx_string_put(mlx->mlx_ptr, mlx->window, 10, 10, blue, "Buttons guide");//mlx->string);
	mlx->image = mlx_string_put(mlx->mlx_ptr, mlx->window, 10, 30, blue, "Move up ↑");//mlx->string);
	mlx->image = mlx_string_put(mlx->mlx_ptr, mlx->window, 10, 50, blue, "Move left ←");//mlx->string);
	mlx->image = mlx_string_put(mlx->mlx_ptr, mlx->window, 10, 70, blue, "Move right →");//mlx->string);
	mlx->image = mlx_string_put(mlx->mlx_ptr, mlx->window, 10, 90, blue, "Move down ↓");//mlx->string);
	// mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian)
	// mlx->image = mlx_pixel_put(mlx->mlx_ptr, mlx->window, 50 + mlx->x, 50 + mlx->y, yellow);
	return (0);
}
