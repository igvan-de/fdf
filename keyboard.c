/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 13:34:37 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/08 19:48:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			reset_grid(t_fdf *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->point->alpha = 0;
	mlx->point->beta = 0;
	mlx->point->gamma = 0;
	mlx->point->z_value = 10;
	mlx->point->zoom = 13;
}

static int			key_rotate_move(int key, t_fdf *mlx)
{
	if (key == KEY_DOWN)
		mlx->y += 10;
	if (key == KEY_RIGHT)
		mlx->x += 10;
	if (key == KEY_UP)
		mlx->y -= 10;
	if (key == KEY_LEFT)
		mlx->x -= 10;
	if (key == ROTATE_DOWN)
		mlx->point->alpha += 0.05;
	if (key == ROTATE_RIGHT)
		mlx->point->beta += 0.05;
	if (key == ROTATE_LEFT)
		mlx->point->beta -= 0.05;
	if (key == ROTATE_UP)
		mlx->point->alpha -= 0.05;
	if (key == Z_LEFT)
		mlx->point->gamma -= 0.05;
	if (key == Z_RIGHT)
		mlx->point->gamma += 0.05;
	return (0);
}

static int			key_change_value(int key, t_fdf *mlx)
{
	if (key == PLUS)
		mlx->point->z_value += 2;
	if (key == MIN)
		mlx->point->z_value -= 2;
	if (mlx->point->keydown != 0 && key == ZOOM_IN)
		mlx->point->zoom += 1 * 5;
	if (mlx->point->keydown != 0 && key == ZOOM_OUT && mlx->point->zoom > 5)
		mlx->point->zoom -= 1 * 5;
	return (0);
}

int					key_press(int key, t_fdf *mlx)
{
	if (key == CONTROL)
		mlx->point->keydown = 1;
	if (key == KEY_ESC)
		close_window(NULL);
	if (key == R)
		reset_grid(mlx);
	key_rotate_move(key, mlx);
	key_change_value(key, mlx);
	return (0);
}

int					key_release(int key, t_fdf *mlx)
{
	if (key == CONTROL)
		mlx->point->keydown = 0;
	return (0);
}
