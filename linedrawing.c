/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linedrawing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 13:56:35 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/21 17:31:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		draw_pixel(int x, int y, float something, t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx_pixel_put(mlx->mlx_ptr, mlx->window, 0 + x + mlx->x, 0 + y + mlx->y, yellow);
	return (0);
}

void			drawaline(int x0, int y0, int x1, int y1, t_fdf *mlx)
{
	int		steep;
	int		x;
	float	fx;
	float	fy;
	float	gradient;
	float	intersect;

	steep = (y1 - y0) > (x1 - x0);
	if(steep)
	{
		ft_swap(&x0, &y1);
		ft_swap(&x0, &y1);
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &y1);
		ft_swap(&x0, &y1);
	}
	fx = x1 - x0;
	fy = y1 - y0;
	gradient = fy / fx;
	if (fx == 0.0)
		gradient = 1;
	intersect = y0;
	x = x0;
	if (steep)
	{
		while (x <= x1)
		{
			draw_pixel(ipartofnumber(intersect), x, fractolofnumber(intersect), mlx);
			draw_pixel(ipartofnumber(intersect) - 1, x, fpartofnumber(intersect), mlx);
			intersect += gradient;
			x++;
		}
	}
	else
	{
		while (x <= x1)
		{
			draw_pixel(x, ipartofnumber(intersect), fractolofnumber(intersect), mlx);
			draw_pixel(x, ipartofnumber(intersect) - 1, fpartofnumber(intersect), mlx);
			intersect += gradient;
			x++;
		}
	}
}
