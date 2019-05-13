/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 14:28:44 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/13 16:12:24 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	window_display(t_fdf *mlx)
{
	mlx->window = mlx_new_window(mlx->mlx_ptr, 1250, 800, "FDF");
}