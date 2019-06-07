/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linear_gradient.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:18:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/07 15:46:42 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;
	double	result;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		result = 1.0;
	else
		result = placement / distance;
	return (result);
}

static int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

static int		color(t_point a, t_point b, double percentage)
{
	int		red;
	int		green;
	int		blue;

	red = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, percentage);
	green = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, percentage);
	blue = get_light(a.color & 0xFF, b.color & 0xFF, percentage);
	return ((red << 16 | green << 8 | blue));
}

int				set_color(int z, t_fdf *mlx)
{
	if (z == 0)
		return (BLUE);
	// else if (z >= 15 && z <= 40)
	// 	return (PURPLE);
	else if (z > 0)
		return (GREEN);
	else if (z < 0)
		return (PURPLE);
	return (0);
}

int				get_color(t_point current, t_point a, t_point b, t_fdf *mlx)
{
	double	percentage;


	if (current.color == b.color)
		return (current.color);
	if (mlx->point->delta_x > mlx->point->delta_y)
		percentage = percent(a.x, b.x, current.x);
	else
		percentage = percent(a.y, b.y, current.y);
	return (color(a, b, percentage));
}


// extra's!
	// a.color = set_color(current.z, mlx);		for color change on the lines!!
	// b.color = set_color(current.z, mlx);		for color change on the lines!!
	// current = (t_point){mlx->point->color, mlx->point->color};  for disco!!!!