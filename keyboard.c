/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 13:34:37 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/05 19:24:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			close_window(void *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}

static void			reset_grid(t_fdf *mlx)
{
	mlx->x = 0;
	mlx->y = 0;
	mlx->point->alpha = 0;
	mlx->point->beta = 0;
	mlx->point->gamma = 0;
	mlx->point->z_value = 10;
}

static int			key_rotate_move(int key, t_fdf *mlx)
{
	if (key == KEY_DOWN)
		mlx->y += 10;
	if (key == KEY_RIGHT)
		mlx->x += 10;
	if (key == KEY_UP)
		mlx->y -= 10;
	if (key == KEY_LEFT) //&& mlx->x >= -40) to make sure it doenst go outside the window
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
	return (0);
}

int					key_press(int key, t_fdf *mlx)
{
	if (key == KEY_ESC)
		close_window(NULL);
	if (key == R)
		reset_grid(mlx);
	key_rotate_move(key, mlx);
	key_change_value(key, mlx);
	// printf("alpha = %f\n", mlx->delta->alpha);
	// ft_printf("%d\n", key);// To check which keynode has which value
	return (0);
}
