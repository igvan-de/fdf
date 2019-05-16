/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 11:41:41 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/16 17:36:09 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ag, char **av)
{
	t_fdf	*mlx;
	t_map	*field;

	field = NULL;
	if (ag == 1)
		return (FALSE);
	mlx = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	field = (t_map*)ft_memalloc(sizeof(t_map));
	mlx->mlx_ptr = mlx_init();
	read_field(av[1], field);
	window_display(mlx);
	image_window(mlx);
	mlx_loop_hook(mlx->mlx_ptr, image_window, mlx);
	mlx_hook(mlx->window, 2, 0, key_press, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (TRUE);
}
