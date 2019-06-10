/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   divide.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:35:47 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/15 13:44:19 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	posneg_null(t_data *data)
{
	if ((data->flags & PLUS_FLAGS) == PLUS_FLAGS ||
		(data->flags & SPACE_FLAGS) == SPACE_FLAGS)
		return (2);
	else
		return (1);
}

int			divide_o(unsigned long long posneg, t_data *data)
{
	int					count;

	count = 0;
	if (data->prec == 0 && data->arg == 0)
		return (0);
	if (posneg == 0)
		return (1);
	while (posneg != 0)
	{
		posneg /= 8;
		count++;
	}
	data->numsize = count;
	if ((data->flags & HASH_FLAGS) == HASH_FLAGS)
		return (count + 1);
	else
		return (count);
}

int			divide_hex(unsigned long long posneg, t_data *data)
{
	int					count;

	count = 0;
	data->numsize = 1;
	if (data->prec == 0 && data->arg == 0)
		return (0);
	if (posneg == 0)
		return (1);
	while (posneg != 0)
	{
		posneg /= 16;
		count++;
	}
	data->numsize = count;
	if ((data->flags & HASH_FLAGS) == HASH_FLAGS)
		return (count + 2);
	else
		return (count);
}

int			divide_l_l(long long posneg, t_data *data)
{
	int			count;

	count = 0;
	if (data->prec == 0 && data->arg == 0)
		return (0);
	if (posneg == 0)
		return (posneg_null(data));
	if ((data->flags & LL_FLAGS) != LL_FLAGS &&
		(data->flags & L_FLAGS) != L_FLAGS)
		posneg = (int)data->arg;
	if ((data->flags & LL_FLAGS) != LL_FLAGS &&
		(data->flags & L_FLAGS) == L_FLAGS)
		posneg = (long)data->arg;
	while (posneg != 0)
	{
		posneg /= 10;
		count++;
	}
	data->numsize = count;
	if ((data->flags & SPACE_FLAGS) == SPACE_FLAGS)
		return (count + 1);
	else if ((data->flags & PLUS_FLAGS) == PLUS_FLAGS)
		return (count + 1);
	else
		return (count + data->arg_neg);
}

int			divide_u_l_l(unsigned long long pos, t_data *data)
{
	int					count;

	count = 0;
	if (pos == 0)
		return (1);
	while (pos != 0)
	{
		pos /= 10;
		count++;
	}
	data->numsize = count;
	if ((data->flags & PLUS_FLAGS) == PLUS_FLAGS)
		return (count + 1);
	else
		return (count);
}
