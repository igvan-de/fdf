/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/26 20:37:51 by igvan-de      ########   odam.nl         */
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
	// printf("a.y = %d b.y = %d\n", a.y, b.y);
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
	// if ((b.y - a.y) < (b.x - a.x))
	drawlineHigh(a, b, mlx);
	drawlineLow(a, b, mlx);
	// else
}

static t_point scale(int x, int y, t_fdf *mlx)
{
	t_point line;

	line.x = x * 30;
	line.y = y * 30;
	return (line);
}

int			draw_grid(t_fdf *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			if (x + 1 <= mlx->map->width && y + 1 <= mlx->map->height)
				plotlines(scale(x, y, mlx), scale(x + 1, y + 1, mlx), mlx);
			// if (y <= mlx->map->height)
			// 	plotlines(scale(x, y, mlx), scale(x + 1, y + 1, mlx), mlx);
			x++;
		}
		y++;
	}
	return (0);
}