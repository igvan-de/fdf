/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linear_gradient.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:18:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/04 14:25:43 by igvan-de      ########   odam.nl         */
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

int				get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(int x, int y, t_fdf *mlx)
{
	int		green;
	int		blue;
	int		yellow;
	t_point	a;
	t_point	b;
	t_point	current;
	double	percentage;

	printf("x = %d\n", a.x);
	printf("y = %d\n", a.y);
	current.x = x;
	// b.x = x + 1;
	current.y = y;
	// b.y = y + 1;
	if (current.color == b.color)
			return (current.color);
	if (mlx->delta->delta_x > mlx->delta->delta_y)
		percentage = percent(a.x, b.x, current.x);
	else
		percentage = percent (a.y, b.y, current.y);
	green = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, percentage);
	blue = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, percentage);
	yellow = get_light(a.color & 0xFF, b.color & 0xFF, percentage);
	return ((green << 16 | blue << 8 | yellow));
}
