/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:34:22 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/29 16:41:48 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		rotation_x(t_point cordinate, t_fdf *mlx)
{
	double		tempx;
	double		tempy;
	double		tempz;

	tempx = cordinate.x;
	tempy = (cordinate.y * cos(mlx->delta->alpha)) + (cordinate.z * sin(mlx->delta->alpha));
	tempz = (-cordinate.y * sin(mlx->delta->alpha)) + (cordinate.z * cos(mlx->delta->alpha));
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

	// printf("beta = %f\n", mlx->delta->beta);
	tempx = (cordinate.x * cos(mlx->delta->beta)) + (cordinate.z * sin(mlx->delta->beta));
	tempy = cordinate.y;
	tempz = (-cordinate.x * sin(mlx->delta->beta)) + (cordinate.z * cos(mlx->delta->beta));
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

	tempx = (cordinate.x * cos(mlx->delta->gamma)) - (cordinate.y * sin(mlx->delta->gamma));
	tempy = (cordinate.x * sin(mlx->delta->gamma)) + (cordinate.y * cos(mlx->delta->gamma));
	tempz = cordinate.z;
	cordinate.x = tempx;
	cordinate.y = tempy;
	cordinate.z = tempz;
	return (cordinate);
}
