/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 11:19:28 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/10 18:16:48 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_num_length(t_data *data)
{
	if (data->conv == 'p')
		data->arg_length = 14;
	if (data->conv == 'p' && data->arg == 0)
		data->arg_length = 3;
	else if ((data->flags & CL_FLAGS) == CL_FLAGS && data->conv == 'f')
		data->arg_length = divide_f_ld(data->arg_ld, data);
	else if ((data->flags & CL_FLAGS) != CL_FLAGS && data->conv == 'f')
		data->arg_length = divide_f_d(data->arg_d, data);
	else if (data->conv == 'o')
		get_o_length(data);
	else if (data->conv == 'x' || data->conv == 'X')
		get_x_length(data);
	else if (data->conv == 'd')
		get_d_length(data);
	else if (data->conv == 'u')
		get_u_length(data);
	return (0);
}

int			get_arg(va_list lst, t_data *data)
{
	if ((data->flags & CL_FLAGS) == CL_FLAGS && data->conv == 'f')
		data->arg_ld = va_arg(lst, long double);
	else if ((data->flags & CL_FLAGS) != CL_FLAGS && data->conv == 'f')
		data->arg_d = va_arg(lst, double);
	else
		data->arg = va_arg(lst, unsigned long long);
	return (0);
}

int			get_neg(t_data *data)
{
	if ((data->flags & CL_FLAGS) == CL_FLAGS && data->conv == 'f'
		&& data->arg_ld < 0)
		data->arg_neg = 1;
	else if ((data->flags & CL_FLAGS) != CL_FLAGS && data->conv == 'f'
			&& data->arg_d < 0)
		data->arg_neg = 1;
	else if ((data->flags & LL_FLAGS) == LL_FLAGS && data->conv == 'd'
			&& (long long)data->arg < 0)
		data->arg_neg = 1;
	else if ((data->flags & L_FLAGS) == L_FLAGS && data->conv == 'd'
			&& (long)data->arg < 0)
		data->arg_neg = 1;
	else if ((data->flags & HH_FLAGS) == HH_FLAGS && data->conv == 'd'
			&& (char)data->arg < 0)
		data->arg_neg = 1;
	else if ((data->flags & H_FLAGS) == H_FLAGS && data->conv == 'd'
			&& (short)data->arg < 0 && (data->flags & HH_FLAGS) != HH_FLAGS)
		data->arg_neg = 1;
	else if (data->conv == 'd' && (int)data->arg < 0 && (data->flags & HH_FLAGS)
			!= HH_FLAGS && (data->flags & L_FLAGS) != L_FLAGS)
		data->arg_neg = 1;
	return (0);
}

int			get_length(t_data *data)
{
	if (data->conv == 's' && !data->arg && (data->flags & PREC_FLAGS)
		!= PREC_FLAGS)
		data->arg_length = 6;
	else if (data->conv == 's' && !data->arg && (data->flags & PREC_FLAGS)
			== PREC_FLAGS && data->prec < 6)
		data->arg_length = data->prec;
	else if (data->conv == 's' && !data->arg && (data->flags & PREC_FLAGS)
			== PREC_FLAGS && data->prec >= 6)
		data->arg_length = 6;
	else if (data->conv == 's' && (data->flags & PREC_FLAGS) != PREC_FLAGS)
		data->arg_length = ft_strlen((char*)data->arg);
	else if (data->conv == 's' && (data->flags & PREC_FLAGS) == PREC_FLAGS &&
			data->prec < (int)ft_strlen((char*)data->arg))
		data->arg_length = data->prec;
	else if (data->conv == 's' && (data->flags & PREC_FLAGS) == PREC_FLAGS &&
			data->prec >= (int)ft_strlen((char*)data->arg))
		data->arg_length = ft_strlen((char*)data->arg);
	else if (data->conv == 'c' || data->conv == '%')
		data->arg_length = 1;
	get_num_length(data);
	return (0);
}
