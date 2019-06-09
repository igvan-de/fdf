/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isometric.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/09 12:31:28 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/09 14:12:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point		iso(t_point line, int x, int y, int z)
{
	int		previous_x;
	int		previous_y;

	previous_x = x;
	previous_y = y;
	line.x = (previous_x - previous_y) * cos(0.523599);
	line.y = ((previous_x + previous_y) * sin(0.523599)) - z;
	return (line);
}
