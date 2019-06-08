/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:34:22 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/08 19:49:18 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point		rotation_x(t_point cordinate, t_fdf *mlx)
{
	double		tempx;
	double		tempy;
	double		tempz;

	tempx = cordinate.x;
	tempy = (cordinate.y * cos(mlx->point->alpha)) +
	(cordinate.z * sin(mlx->point->alpha));
	tempz = (-cordinate.y * sin(mlx->point->alpha)) +
	(cordinate.z * cos(mlx->point->alpha));
	cordinate.x = tempx;
	cordinate.y = tempy;
	cordinate.z = tempz;
	return (cordinate);
}

t_point		rotation_y(t_point cordinate, t_fdf *mlx)
{
	double		tempx;
	double		tempy;
	double		tempz;

	tempx = (cordinate.x * cos(mlx->point->beta)) +
	(cordinate.z * sin(mlx->point->beta));
	tempy = cordinate.y;
	tempz = (-cordinate.x * sin(mlx->point->beta)) +
	(cordinate.z * cos(mlx->point->beta));
	cordinate.x = tempx;
	cordinate.y = tempy;
	cordinate.z = tempz;
	return (cordinate);
}

t_point		rotation_z(t_point cordinate, t_fdf *mlx)
{
	double		tempx;
	double		tempy;
	double		tempz;

	tempx = (cordinate.x * cos(mlx->point->gamma)) -
	(cordinate.y * sin(mlx->point->gamma));
	tempy = (cordinate.x * sin(mlx->point->gamma)) +
	(cordinate.y * cos(mlx->point->gamma));
	tempz = cordinate.z;
	cordinate.x = tempx;
	cordinate.y = tempy;
	cordinate.z = tempz;
	return (cordinate);
}
