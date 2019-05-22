/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 11:41:41 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/22 18:43:27 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		menu(void)
{
	ft_printf("\033[1;32m");
	ft_printf("BUTTONS GUIDE\n");
	ft_printf("\033[0m");
	ft_printf("Keyboard movements:\n Up	↑\n Left  ← →  Right\n Down	↓\n");
}

int				main(int ag, char **av)
{
	t_fdf	*mlx;
	if (ag == 1)
		return (0);
	mlx = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	mlx->map = (t_map*)ft_memalloc(sizeof(t_map));
	mlx->mlx_ptr = mlx_init();
	set_field(av[1], mlx->map);
	if (ag == 3 && ft_strequ(av[2], "--menu"))
		menu();
	window_display(mlx);
	image_window(mlx);
	mlx_loop_hook(mlx->mlx_ptr, image_window, mlx);
	mlx_hook(mlx->window, 2, 0, key_press, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
