/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 13:50:16 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/11 13:53:21 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_error(int a, int b)
{
	if (a != b)
	{
		ft_printf("Not a valid map\n");
		return (FALSE);
	}
	return (TRUE);
}
