/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/26 19:04:20 by igvan-de      ########   odam.nl         */
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

static void		drawlineLow(t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	if (a.x > b.x)
	{
		ft_swap(&a.x, &b.x);
		ft_swap(&a.y, &b.y);
	}
	delta = (2 * mlx->delta->delta_y) - mlx->delta->delta_x;
	while (a.x < b.x)
	{
		put_pixel(a.x, a.y, mlx);
		if (delta > 0)
		{
			a.y = a.y + mlx->negative;
			delta = delta - (2 * mlx->delta->delta_x);
		}
		delta = delta + (2 * mlx->delta->delta_y);
		a.x++;
	}
}

static void		drawlineHigh(t_point a, t_point b, t_fdf *mlx)
{
	int		delta;

	if (a.y > b.y)
	{
		ft_swap(&a.x, &b.x);
		ft_swap(&a.y, &b.y);
	}
	delta = (2 * mlx->delta->delta_x) - mlx->delta->delta_y;
	while (a.y < b.y)
	{
		put_pixel(a.x, a.y, mlx);
		if (delta > 0)
		{
			a.x = a.x  + mlx->negative;
			delta = delta - (2 * mlx->delta->delta_y);
		}
		delta = delta + (2 * mlx->delta->delta_x);
		a.y++;
	}
}

static void		plotlines(t_point a, t_point b, t_fdf *mlx)
{
	mlx->delta->delta_x = (b.x - a.x);
	mlx->delta->delta_y = (b.y - a.y);
	if (mlx->delta->delta_x < 0)
	{
		mlx->negative = -1;
		mlx->delta->delta_x = -mlx->delta->delta_x;
	}
	if (mlx->delta->delta_y < 0)
	{
		mlx->negative = -1;
		mlx->delta->delta_y = -mlx->delta->delta_y;
	}
	if ((b.y - a.y) < (b.x - a.x))
		drawlineHigh(a, b, mlx);
	else
		drawlineLow(a, b, mlx);
}

static void	scale(int x)
{
	x = x * 30;
}

int				test(t_fdf *mlx)
{
	t_point a;
	t_point b;

	a.x = 0;
	a.y = 0;	//y0
	b.y = 0;	//y1
	while (b.y < mlx->map->height)
	{
		b.x = 0;
		while (b.x < mlx->map->width)
		{
			if (b.x <= mlx->map->width)
				plotlines(scale_x(x), y, mlx);
			if (b.y <= mlx->map->width)
				plotlines(x, y, mlx);
			a.x++;
			b.x++;
			printf("a.x= %d b.x = %d a.y = %d b.y = %d\n", a.x, b.x, a.y, b.y);
		}
		a.y++;
		b.y++;
	}
	return (0);
}
