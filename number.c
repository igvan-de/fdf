/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 17:13:28 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/21 17:15:03 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	absolute(float x)
{
	if(x < 0)
		return (-x);
	return (x);
}

float	fpartofnumber(float x)
{
	if (x < 0)
		return(x - ipartofnumber(x));
	else
		return(x - ipartofnumber(x) + 1);
}

float	fractolofnumber(float x)
{
	return (1 - fpartofnumber(x));
}

int		ipartofnumber(float x)
{
	return((int)x);
}

int		roundnumber(float x)
{
	return(ipartofnumber(x + 0.5));
}
