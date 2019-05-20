/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keyboard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 13:34:37 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/20 15:42:14 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			close_window(void *ptr)
{
	(void)ptr;
	exit(0);
	return (0);
}

int					key_press(int key, t_fdf *mlx)
{
	if (key == KEY_ESC)
		close_window(NULL);
	if (key == KEY_DOWN)
		mlx->y += 10;
	if (key == KEY_RIGHT)
		mlx->x += 10;
	if (key == KEY_UP)
		mlx->y -= 10;
	if (key == KEY_LEFT && mlx->x >= -40)
		mlx->x -= 10;
	// ft_printf("%d\n", key); To check which keynode has which value
	return (TRUE);
}
