/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linear_gradient.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:18:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/04 17:57:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		color(t_point a, t_point b, double percentage)
{
	int		green;
	int		blue;
	int		yellow;

	green = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, percentage);
	blue = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, percentage);
	yellow = get_light(a.color & 0xFF, b.color & 0xFF, percentage);
	return ((green << 16 | blue << 8 | yellow));
}

int				get_color(int x, int y, t_fdf *mlx)
{
	t_point	a;
	t_point	b;
	t_point	current;
	double	percentage;

	a.x = mlx->delta->x;
	b.x = mlx->delta->x + 1;
	a.y = mlx->delta->y;
	b.y = mlx->delta->y + 1;
	current.x = x;
	current.y = y;
	if (current.color == b.color)
			return (current.color);
	if (mlx->delta->delta_x > mlx->delta->delta_y)
		percentage = percent(a.x, b.x, current.x);
	else
		percentage = percent (a.y, b.y, current.y);
	return (color(a, b, percentage));
}
