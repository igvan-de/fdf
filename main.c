/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 11:41:41 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/13 18:03:00 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ag, char **av)
{
	t_fdf	*mlx;

	if (ag == 1)
		return (FALSE);
	mlx = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	mlx->mlx_ptr = mlx_init();
	read_fd(av[1], mlx);
	window_display(mlx);
	image_window(mlx);
	mlx_loop_hook(mlx->mlx_ptr, image_window, mlx);
	mlx_hook(mlx->window, 2, 0, key_press, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (TRUE);
}
