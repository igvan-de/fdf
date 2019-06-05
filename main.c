/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 11:41:41 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/05 19:27:47 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		menu(void)
{
	ft_printf("\033[1;32m");
	ft_printf("BUTTONS GUIDE\n");
	ft_printf("\033[0m");
	ft_printf("Keyboard movements:\n Up	↑\n Left  ← →  Right\n Down	↓\n");
	ft_printf("Press A to rotate to left\nPress D to rotate to right\n");
	ft_printf("Press W to rotate upwards\nPress S to rotate downwards\n");
	ft_printf("Press Z to rotate z_value to left\nPress X to rotate z_value to right\n");
	ft_printf("Press + to increase z_value\nPress - to decrease z_value\n");
}

static void		set_mlx(t_fdf **mlx)
{
	*mlx = (t_fdf*)ft_memalloc(sizeof(t_fdf));
	(*mlx)->map = (t_map*)ft_memalloc(sizeof(t_map));
	(*mlx)->point = (t_point*)ft_memalloc(sizeof(t_point));
	(*mlx)->point->alpha = 0;
	(*mlx)->point->beta = 0;
	(*mlx)->point->gamma = 0;
	(*mlx)->mlx_ptr = mlx_init();
	(*mlx)->point->z_value = 10;
}

int				main(int ag, char **av)
{
	t_fdf	*mlx;	

	if (ag == 1)
		return (put_input());
	set_mlx(&mlx);
	set_map(av[1], mlx->map);
	if (ag == 3 && ft_strequ(av[2], "--menu"))
		menu();
	window_display(mlx);
	image_window(mlx);
	mlx_loop_hook(mlx->mlx_ptr, image_window, mlx);
	mlx_hook(mlx->window, 2, 0, key_press, mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
