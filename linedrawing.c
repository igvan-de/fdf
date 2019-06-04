/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/04 16:18:13 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		drawlineLow(t_point a, t_point b, t_fdf *mlx)
{
	int		delta;
	t_point	cur_point;

	mlx->delta->delta_x = (b.x - a.x);
	mlx->delta->delta_y = (b.y - a.y);
	mlx->increase = 1;
	if (mlx->delta->delta_y < 0)
	{
		mlx->increase = -1;
		mlx->delta->delta_y *= -1;
	}
	delta = (2 * mlx->delta->delta_y) - mlx->delta->delta_x;
	cur_point = a;
	while (cur_point.x < b.x)
	{
		put_pixel(cur_point.x, cur_point.y, mlx);
		if (delta > 0)
		{
			cur_point.y = cur_point.y + mlx->increase;
			delta = delta - (2 * mlx->delta->delta_x);
		}
		delta = delta + (2 * mlx->delta->delta_y);
		cur_point.x++;
	}
}

static void		drawlineHigh(t_point a, t_point b, t_fdf *mlx)
{
	int		delta;
	t_point	cur_point;

	mlx->delta->delta_x = (b.x - a.x);
	mlx->delta->delta_y = (b.y - a.y);
	mlx->increase = 1;
	if (mlx->delta->delta_x < 0)
	{
		mlx->increase = -1;
		mlx->delta->delta_x *= -1;
	}
	delta = (2 * mlx->delta->delta_x) - mlx->delta->delta_y;
	cur_point = a;
	while (cur_point.y < b.y)
	{
		put_pixel(cur_point.x, cur_point.y, mlx);
		if (delta > 0)
		{
			cur_point.x = cur_point.x + mlx->increase;
			delta = delta - (2 * mlx->delta->delta_y);
		}
		delta = delta + (2 * mlx->delta->delta_x);
		cur_point.y++;
	}
}

static void		plotlines(t_point a, t_point b, t_fdf *mlx)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
		{
			ft_swap(&a.x, &b.x);
			ft_swap(&a.y, &b.y);
		}
		drawlineLow(a, b, mlx);
	}
	else
	{
		if (a.y > b.y)
		{
			ft_swap(&a.x, &b.x);
			ft_swap(&a.y, &b.y);
		}
		drawlineHigh(a, b, mlx);
	}
}

static t_point	scale(int x, int y, t_fdf *mlx)
{
	t_point line;

	line.x = x * 23;
	line.y = y * 23;
	line.z = mlx->map->map[y][x] * mlx->delta->z_value;
	line = rotation_x(line, mlx);
	line = rotation_y(line, mlx);
	line = rotation_z(line, mlx);
	return (line);
}

int				draw_grid(t_fdf *mlx)
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
			if (x + 1 < mlx->map->width)
				plotlines(scale(x, y, mlx), scale(x + 1, y, mlx), mlx);
			if (y + 1 < mlx->map->height)
				plotlines(scale(x, y, mlx), scale(x, y + 1, mlx), mlx);
			x++;
		}
		y++;
	}
	return (0);
}
