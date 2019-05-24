/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 13:56:35 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/24 18:18:43 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		draw_pixel(int x, int y, float something, t_fdf *mlx)
{
	mlx_clear_window(mlx->mlx_ptr, mlx->window);
	mlx_pixel_put(mlx->mlx_ptr, mlx->window, x + mlx->x, y + mlx->y, yellow);
	return (0);
}

static void			drawaline_x(int x0, int y0, int x1, int y1, t_fdf *mlx)
{
	int		steep;
	int		x;
	float	fx;
	float	fy;
	float	gradient;
	float	intersect;

	// printf("x = %d x1 = %d y = %d y1 = %d\n", x0, x1, y0, y1);
	steep = (y1 - y0) > (x1 - x0);
	if(steep)
	{
		ft_swap(&x0, &y0);
		ft_swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
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
			draw_pixel(ipartofnumber(intersect), x, fractolofnumber(intersect), mlx);
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

static void			drawaline_y(int x0, int y0, int x1, int y1, t_fdf *mlx)
{
	int		steep;
	int		y;
	float	fx;
	float	fy;
	float	gradient;
	float	intersect;

	steep = (y0 - y1) > (x0 - x1);
	if(steep)
	{
		ft_swap(&x0, &y1);
		ft_swap(&x1, &y1);
	}
	if (x1 > x0)
	{
		ft_swap(&x0, &x1);
		ft_swap(&y0, &y1);
	}
	fx = x0 - x1;
	fy = y0 - y1;
	gradient = fx / fy;
	if (fy == 0.0)
		gradient = 1;
	intersect = x0;
	y = y0;
	if (steep)
	{
		while (y >= y1)
		{
			draw_pixel(ipartofnumber(intersect), y, fractolofnumber(intersect), mlx);
			draw_pixel(ipartofnumber(intersect), y, fractolofnumber(intersect), mlx);
			intersect += gradient;
			y--;
		}
	}
	else
	{
		while (y >= y1)
		{
			draw_pixel(y, ipartofnumber(intersect), fractolofnumber(intersect), mlx);
			draw_pixel(y, ipartofnumber(intersect) - 1, fpartofnumber(intersect), mlx);
			intersect += gradient;
			y--;
		}
	}
}

void	wich_line(int x0, int y0, int x1, int y1, t_fdf *mlx)
{
	if (x0 <= x1 && y0 <= y1)
		drawaline_x(x0, y0, x1, y1, mlx);
	else
		drawaline_y(x0, y0, x1, y1, mlx);
}

// t_line				set_cordinates(int x, int y, t_fdf *mlx)
// {
// 	t_line	line;

// 	line.x = x * 30;
// 	line.y = y * 30;
// 	// line.z = mlx->map->field[y][x];
// 	return (line);
// }

void			draw_map(t_fdf *mlx)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = 0;
	y = 0;
	while (y < mlx->map->height)
	{
		x = 0;
		while (x < mlx->map->width)
		{
			// start = set_cordinates(x, y, mlx);		
			// end = set_cordinates(x + 1, y, mlx);
			if (x + 1 <= mlx->map->width)
				wich_line(x, x1, y, y1, mlx);
			// end = set_cordinates(x, y + 1, mlx);
			// printf("x = %d y = %d\n", x, y);
			if (y + 1 <= mlx->map->height)
				wich_line(x, x1, y, y1, mlx);
			x++;
		}
		y++;
	}
}
