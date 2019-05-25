/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/25 17:55:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		put_pixel(int x, int y, t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx_pixel_put(mlx->mlx_ptr, mlx->window, x + mlx->x, y + mlx->y, yellow);
	return (0);
}

static void	drawlineLow(int y, int x, t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	delta = (2 * y) - x;
	while (a.x < b.x || a.x > b.x)
	{
		put_pixel(a.x, a.y, mlx);
		if (delta > 0)
		{
			if (a.x < b.x)
				a.y++;
			if (a.x > b.x)
				a.y--;
			delta = delta - (2 * x);
		}
		delta = delta + (2 * y);
		if (a.x < b.x)
			a.x++;
		if (a.x > b.x)
			a.x--;
	}
}

static void	drawlineHigh(int y, int x, t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	printf("test2\n");
	delta = (2 * x) - y;
	while (a.y < b.y || a.y > b.y)
	{
		put_pixel(a.x, a.y, mlx);
		if (delta > 0)
		{
			if (a.y < b.y)
				a.x++;
			if (a.y > b.y)
				a.x--;
			delta = delta - (2 * y);
		}
		delta = delta + (2 * x);
		if (a.y < b.y)
			a.y++;
		if (a.y > b.y)
			a.y--;
	}
}

void		plotlines(t_point a, t_point b, t_fdf *mlx)
{
	int		delta_x;
	int		delta_y;

	delta_x = (b.x - a.x);
	delta_y = (b.y - a.y);
	if (delta_x < 0)
		delta_x = -delta_x;
	if (delta_y < 0)
		delta_y = -delta_y;
	//printf("a.x = %d b.x = %d a.y = %d b.y = %d\n", a.x, b.x, a.y, b.y);
	if ((b.y - a.y) < (b.x - a.x))
		drawlineLow(delta_y, delta_x, a, b, mlx);
	else
		drawlineLow(delta_y, delta_x, a, b, mlx);
}

int test(t_fdf *mlx)
{
	t_point a;
	t_point b;

	a.x = 300;	//x0
	a.y = 300;	//y0
	b.x = 100;	//x1
	b.y = 50;	//y1
	plotlines(a, b, mlx);
	return (0);
}