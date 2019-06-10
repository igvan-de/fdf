/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide_fl.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 16:00:29 by igvan-de       #+#    #+#                */
/*   Updated: 2019/04/24 12:33:41 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		divide_f_ld(long double flo, t_data *data)
{
	int			count;
	long long	tmp;

	count = 0;
	tmp = flo;
	while (tmp != 0)
	{
		tmp /= 10;
		count++;
	}
	if (data->prec == 0 && (data->flags & HASH_FLAGS) == HASH_FLAGS)
		return (count + 1 + data->arg_neg);
	else if (data->prec > 0 && (data->flags & PLUS_FLAGS) == PLUS_FLAGS)
		return (count + data->prec + 2 + data->arg_neg);
	else if (data->prec > 0 && (data->flags & SPACE_FLAGS) == SPACE_FLAGS)
		return (count + data->prec + 2 + data->arg_neg);
	else if (data->prec == 0)
		return (count + data->arg_neg);
	else
		return (count + data->prec + 1 + data->arg_neg);
}

int		divide_f_d(double flo, t_data *data)
{
	int			count;
	long long	tmp;

	count = 0;
	tmp = flo;
	while (tmp != 0)
	{
		tmp /= 10;
		count++;
	}
	if (data->prec == 0 && (data->flags & HASH_FLAGS) == HASH_FLAGS)
		return (count + 1 + data->arg_neg);
	else if (data->prec > 0 && (data->flags & PLUS_FLAGS) == PLUS_FLAGS)
		return (count + data->prec + 2 + data->arg_neg);
	else if (data->prec > 0 && (data->flags & SPACE_FLAGS) == SPACE_FLAGS)
		return (count + data->prec + 2) + data->arg_neg;
	else if (data->prec == 0)
		return (count + data->arg_neg);
	else
		return (count + data->prec + 1 + data->arg_neg);
}
