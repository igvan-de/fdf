/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/11 13:50:16 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/24 17:07:08 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**map_error(void)
{
	ft_printf("Not a valid map\n");
	exit(0);
}

int		put_input(void)
{
	ft_printf("Please give file to execute\n");
	exit(0);
}
