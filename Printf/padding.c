/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 19:58:24 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/05/02 16:11:52 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			padding_all(t_data *data)
{
	int		fill;

	fill = data->width - data->arg_length;
	if (data->conv == 'd' && (data->flags & NULL_FLAGS) != NULL_FLAGS &&
		(data->flags & PREC_FLAGS) == PREC_FLAGS && data->arg_neg == 1
		&& data->prec > data->numsize)
		fill--;
	if (data->conv == 'd' && (((data->flags & PLUS_FLAGS) == PLUS_FLAGS)
		|| (data->flags & SPACE_FLAGS) == SPACE_FLAGS))
		fill--;
	while (fill > 0)
	{
		ft_putchar_ret(' ', data);
		fill--;
	}
	return (0);
}
