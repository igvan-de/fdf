/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handler.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 12:11:38 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/10 17:59:58 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_handler(t_data *data)
{
	if ((data->flags & MIN_FLAGS) != MIN_FLAGS)
		padding_ton(data);
	print_flags(data);
	if ((data->conv == 'x' || data->conv == 'X') && ((data->flags & NULL_FLAGS)
		!= NULL_FLAGS || (data->flags & MIN_FLAGS) == MIN_FLAGS))
		print_xo_flags(data);
	if ((data->flags & PREC_FLAGS) == PREC_FLAGS)
		print_prec(data);
	if (data->conv == 'f')
		print_floats(data);
	if (ft_strchr("duoxXb", data->conv))
	{
		if (data->conv == 'o')
			print_xo_flags(data);
		print_nums(data);
	}
	if (ft_strchr("csp%", data->conv))
	{
		print_chars(data);
	}
	if ((data->flags & MIN_FLAGS) == MIN_FLAGS)
		padding_ton(data);
	return (0);
}

int			arg_handler(const char *format, va_list lst, t_data *data)
{
	zero_struct(data);
	check_flags(format, lst, data);
	check_conv(format, data);
	if (data->conv == '0')
		return (0);
	check_prec_width(format, data);
	if (ft_strchr(CONVS, data->conv) && data->conv != '%')
	{
		get_arg(lst, data);
		get_neg(data);
	}
	get_length(data);
	print_handler(data);
	return (0);
}
