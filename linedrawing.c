/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/24 20:29:53 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		put_pixel(int x, int y, t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx_pixel_put(mlx->mlx_ptr, mlx->window, x + mlx->x, y + mlx->y, yellow);
	return (0);
}

static void	plotlineLow(int y, int x, int a, int b, t_fdf *mlx)
{
	int		delta;
	int		i;

	delta = (2 * y) - x;
	i = 0;
	while (i < mlx->map->width)
	{
		put_pixel(a, b, mlx);
		if (delta > 0)
		{
			i++;
			delta = delta - (2 * x);
		}
		delta = delta + (2 * y);
	}
}

static void	plotlineHigh(int y, int x, t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	printf("test2\n");
	delta = (2*x) - y;
	while (b.y < mlx->map->height)
	{
		put_pixel(a.y, b.y, mlx);
		if (delta > 0)
		{
			x++;
			delta = delta - (2 * y);
		}
		delta = delta + (2 * x);
	}
}

void		draw_lines(t_point a, t_point b, t_fdf *mlx)
{
	int		delta_x;
	int		delta_y;

	delta_x = (b.x - a.x);
	delta_y = (b.y - a.y);
	if (delta_x < 0 || delta_y < 0)	//Na deze if statement zijn a.x & a.y altijd groter dan b.x & b.y!
	{
		ft_swap(&a.x, &b.x);
		ft_swap(&b.y, &b.y);
		if (delta_x < 0)
			delta_x = -delta_x;
		if (delta_y < 0)
			delta_y = -delta_y;
	}
	if (ABS(a.y - b.y) > ABS(a.x - b.x))
		plotlineLow(delta_y, delta_x, a.x, b.x, mlx);
	else
		plotlineHigh(delta_y, delta_x, a, b, mlx);
}

int test(t_fdf *mlx)
{
	t_point a;
	t_point b;

	a.x = 200;
	a.y = 100;
	b.x = 100;
	b.y = 300;
	draw_lines(a, b, mlx);
	return (0);
}