/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 17:39:26 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/07 17:21:00 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		drawlineLow(t_point a, t_point b, t_fdf *mlx)
{
	int		delta;
	t_point	cur_point;

	mlx->point->delta_x = (b.x - a.x);
	mlx->point->delta_y = (b.y - a.y);
	mlx->increase = 1;
	if (mlx->point->delta_y < 0)
	{
		mlx->increase = -1;
		mlx->point->delta_y *= -1;
	}
	delta = (2 * mlx->point->delta_y) - mlx->point->delta_x;
	cur_point = a;
	while (cur_point.x < b.x)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->window, 420 + cur_point.x + mlx->x,
		200 + cur_point.y + mlx->y, get_color(cur_point, a, b, mlx));
		if (delta > 0)
		{
			cur_point.y = cur_point.y + mlx->increase;
			delta = delta - (2 * mlx->point->delta_x);
		}
		delta = delta + (2 * mlx->point->delta_y);
		cur_point.x++;
	}
}

static void		drawlineHigh(t_point a, t_point b, t_fdf *mlx)
{
	int		delta;
	t_point	cur_point;

	mlx->point->delta_x = (b.x - a.x);
	mlx->point->delta_y = (b.y - a.y);
	mlx->increase = 1;
	if (mlx->point->delta_x < 0)
	{
		mlx->increase = -1;
		mlx->point->delta_x *= -1;
	}
	delta = (2 * mlx->point->delta_x) - mlx->point->delta_y;
	cur_point = a;
	while (cur_point.y < b.y)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->window, 420 + cur_point.x + mlx->x,
		200 + cur_point.y + mlx->y, get_color(cur_point, a, b, mlx));
		if (delta > 0)
		{
			cur_point.x = cur_point.x + mlx->increase;
			delta = delta - (2 * mlx->point->delta_y);
		}
		delta = delta + (2 * mlx->point->delta_x);
		cur_point.y++;
	}
}

static void		plotlines(t_point a, t_point b, t_fdf *mlx)
{
	if (abs(b.y - a.y) < abs(b.x - a.x))
	{
		if (a.x > b.x)
			drawlineLow(b, a, mlx);
		else
			drawlineLow(a, b, mlx);
	}
	else
	{
		if (a.y > b.y)
			drawlineHigh(b, a, mlx);
		else
			drawlineHigh(a, b, mlx);
	}
}

static t_point	scale(int x, int y, t_fdf *mlx)
{
	t_point line;

	line.x = x * 23;
	line.y = y * 23;
	line.z = mlx->map->map[y][x] * mlx->point->z_value;
	line.color = set_color(line.z, mlx);
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
