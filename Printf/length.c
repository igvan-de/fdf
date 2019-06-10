/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   length.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 13:31:16 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/15 13:39:00 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_d_length(t_data *data)
{
	if ((data->flags & HH_FLAGS) == HH_FLAGS)
		data->arg_length = divide_l_l((char)data->arg, data);
	else if ((data->flags & H_FLAGS) == H_FLAGS)
		data->arg_length = divide_l_l((short)data->arg, data);
	else if ((data->flags & LL_FLAGS) == LL_FLAGS)
		data->arg_length = divide_l_l((long long)data->arg, data);
	else if ((data->flags & L_FLAGS) == L_FLAGS)
		data->arg_length = divide_l_l((long)data->arg, data);
	else if ((int)data->arg == 0 && data->prec != 0 &&
		(data->flags & PLUS_FLAGS) != PLUS_FLAGS &&
		(data->flags & SPACE_FLAGS) != SPACE_FLAGS)
		data->arg_length = 1;
	else
		data->arg_length = divide_l_l((int)data->arg, data);
	if (data->arg_length < data->prec && (data->flags & PREC_FLAGS)
		== PREC_FLAGS)
		data->arg_length = data->prec;
	return (0);
}

int		get_o_length(t_data *data)
{
	if (data->conv == 'o' && (data->flags & HH_FLAGS) == HH_FLAGS)
		data->arg_length = divide_o((unsigned char)data->arg, data);
	else if (data->conv == 'o' && (data->flags & H_FLAGS) == H_FLAGS)
		data->arg_length = divide_o((unsigned short)data->arg, data);
	else if (data->conv == 'o' && (data->flags & LL_FLAGS) == LL_FLAGS)
		data->arg_length = divide_o((unsigned long long)data->arg, data);
	else if (data->conv == 'o' && (data->flags & L_FLAGS) == L_FLAGS)
		data->arg_length = divide_o((unsigned long)data->arg, data);
	else
		data->arg_length = divide_o((unsigned int)data->arg, data);
	if (data->arg_length < data->prec && (data->flags & PREC_FLAGS)
		== PREC_FLAGS)
		data->arg_length = data->prec;
	return (0);
}

int		get_x_length(t_data *data)
{
	if (data->conv == 'x' && (data->flags & HH_FLAGS) == HH_FLAGS)
		data->arg_length = divide_hex((unsigned char)data->arg, data);
	else if (data->conv == 'x' && (data->flags & H_FLAGS) == H_FLAGS)
		data->arg_length = divide_hex((unsigned short)data->arg, data);
	else if (data->conv == 'x' && (data->flags & LL_FLAGS) == LL_FLAGS)
		data->arg_length = divide_hex((unsigned long long)data->arg, data);
	else if (data->conv == 'x' && (data->flags & L_FLAGS) == L_FLAGS)
		data->arg_length = divide_hex((unsigned long)data->arg, data);
	else
		data->arg_length = divide_hex((unsigned int)data->arg, data);
	if (data->arg_length < data->prec && (data->flags & PREC_FLAGS)
		== PREC_FLAGS)
	{
		data->arg_length = data->prec;
		if ((data->flags & HASH_FLAGS) == HASH_FLAGS)
			data->arg_length += 2;
	}
	if (data->prec < data->arg_length && (data->flags & HASH_FLAGS)
		== HASH_FLAGS && data->prec != 0)
		data->arg_length++;
	return (0);
}

int		get_u_length(t_data *data)
{
	if (data->conv == 'u' && (data->flags & HH_FLAGS) == HH_FLAGS)
		data->arg_length = divide_u_l_l((unsigned char)data->arg, data);
	else if (data->conv == 'u' && (data->flags & H_FLAGS) == H_FLAGS)
		data->arg_length = divide_u_l_l((unsigned short)data->arg, data);
	else if (data->conv == 'u' && (data->flags & LL_FLAGS) == LL_FLAGS)
		data->arg_length = divide_u_l_l((unsigned long long)data->arg, data);
	else if (data->conv == 'u' && (data->flags & L_FLAGS) == L_FLAGS)
		data->arg_length = divide_u_l_l((unsigned long)data->arg, data);
	else if ((unsigned int)data->arg == 0 && data->prec != 0)
		data->arg_length = 1;
	else
		data->arg_length = divide_u_l_l((unsigned int)data->arg, data);
	if (data->arg_length < data->prec && (data->flags & PREC_FLAGS)
		== PREC_FLAGS)
		data->arg_length = data->prec;
	return (0);
}
