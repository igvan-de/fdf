/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 15:34:22 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/27 17:49:53 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point     rotation_x(t_point cordinate, t_fdf *mlx)
{
    cordinate.x = cordinate.x;
    cordinate.y = (cordinate.y * cos(mlx->delta->alpha)) + (cordinate.z * sin(mlx->delta->alpha));
    cordinate.z = (-cordinate.y * sin(mlx->delta->alpha)) + (cordinate.z * cos(mlx->delta->alpha));
    return (cordinate);
}

t_point     rotation_y(t_point cordinate, t_fdf *mlx)
{
    cordinate.x = (cordinate.x * cos(mlx->delta->beta)) + (cordinate.z * sin(mlx->delta->beta));
    cordinate.y = cordinate.y;
    cordinate.z = (-cordinate.x * sin(mlx->delta->beta)) + (cordinate.z * cos(mlx->delta->beta));
    return (cordinate);
}

t_point     rotation_z(t_point cordinate, t_fdf *mlx)
{
    cordinate.x = (-cordinate.x * cos(mlx->delta->gamma)) + (cordinate.z * sin(mlx->delta->gamma));
    cordinate.y = (-cordinate.y * sin(mlx->delta->gamma)) + (cordinate.z * cos(mlx->delta->gamma));
    cordinate.z = cordinate.z;
    return (cordinate);
}
