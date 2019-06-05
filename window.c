/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 14:28:44 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/05 14:10:40 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_display(t_fdf *mlx)
{
	mlx->window = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "FDF");
}

int		image_window(t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx->image = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	mlx->placement = mlx_put_image_to_window(mlx->mlx_ptr, mlx->window,
	mlx->image, 650, 450);
	draw_grid(mlx);
	return (0);
}
