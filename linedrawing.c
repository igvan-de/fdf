/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/25 19:46:20 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		put_pixel(int x, int y, t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx_pixel_put(mlx->mlx_ptr, mlx->window, 400 + x + mlx->x,
	100 + y + mlx->y, yellow);
	return (0);
}

static void		drawlineLow(int y, int x, t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	if (a.x > b.x)
	{
		ft_swap(&a.x, &b.x);
		ft_swap(&a.y, &b.y);
	}
	delta = (2 * y) - x;
	while (a.x < b.x)
	{
		put_pixel(a.x, a.y, mlx);
		if (delta > 0)
		{
			a.y = a.y + mlx->negative;
			delta = delta - (2 * x);
		}
		delta = delta + (2 * y);
		a.x++;
	}
}

static void		drawlineHigh(int y, int x, t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	if (a.x > b.x)
	{
		ft_swap(&a.x, &b.x);
		ft_swap(&a.y, &b.y);
	}
	delta = (2 * x) - y;
	while (a.y < b.y)
	{
		put_pixel(a.x, a.y, mlx);
		if (delta > 0)
		{
			a.x = a.x  + mlx->negative;
			delta = delta - (2 * y);
		}
		delta = delta + (2 * x);
		a.y++;
	}
}

void			plotlines(t_point a, t_point b, t_fdf *mlx)
{
	int		delta_x;
	int		delta_y;

	delta_x = (b.x - a.x);
	delta_y = (b.y - a.y);
	if (delta_x < 0)
	{
		mlx->negative = -1;
		delta_x = -delta_x;
	}
	if (delta_y < 0)
	{
		mlx->negative = -1;
		delta_y = -delta_y;
	}
	if ((b.y - a.y) < (b.x - a.x))
		drawlineHigh(delta_y, delta_x, a, b, mlx);
	else
		drawlineLow(delta_y, delta_x, a, b, mlx);
}

int				test(t_fdf *mlx)
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
