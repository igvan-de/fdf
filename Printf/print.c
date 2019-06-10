/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 16:07:57 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/08 16:03:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						print_floats(t_data *data)
{
	if ((data->flags & NULL_FLAGS) != NULL_FLAGS &&
		data->arg_neg == 1 && (data->flags & PMIN_FLAGS) != PMIN_FLAGS)
	{
		ft_putchar_ret('-', data);
		data->flags |= PMIN_FLAGS;
	}
	if ((data->flags & CL_FLAGS) == CL_FLAGS)
		ftoa_long(data->arg_ld, data->prec, data);
	else
		ftoa(data->arg_d, data->prec, data);
	return (0);
}

static int				print_oct(t_data *data)
{
	if (data->conv == 'o' && (data->flags & HH_FLAGS) == HH_FLAGS)
		putnbr_u_l((unsigned char)data->arg, 8, data);
	else if (data->conv == 'o' && (data->flags & H_FLAGS) == H_FLAGS)
		putnbr_u_l((unsigned short)data->arg, 8, data);
	else if (data->conv == 'o' && (data->flags & LL_FLAGS) == LL_FLAGS)
		putnbr_u_l((unsigned long long)data->arg, 8, data);
	else if (data->conv == 'o' && (data->flags & L_FLAGS) == L_FLAGS)
		putnbr_u_l((unsigned long)data->arg, 8, data);
	else if (ft_strchr("ou", data->conv) && ((data->flags & PREC_FLAGS)
		== PREC_FLAGS || (data->flags & HASH_FLAGS) == HASH_FLAGS)
		&& (unsigned long)data->arg == 0)
		return (0);
	else if (data->conv == 'o')
		putnbr_u_l((unsigned int)data->arg, 8, data);
	else
		print_hex(data);
	return (0);
}

static int				print_un(t_data *data)
{
	if (data->conv == 'u' && (data->flags & HH_FLAGS) == HH_FLAGS)
		putnbr_u_l((unsigned char)(data->arg), 10, data);
	else if (data->conv == 'u' && (data->flags & H_FLAGS) == H_FLAGS)
		putnbr_u_l((unsigned short)data->arg, 10, data);
	else if (data->conv == 'u' && (data->flags & LL_FLAGS) == LL_FLAGS)
		putnbr_u_l((unsigned long long)data->arg, 10, data);
	else if (data->conv == 'u' && (data->flags & L_FLAGS) == L_FLAGS)
		putnbr_u_l((unsigned long)data->arg, 10, data);
	else if (data->conv == 'u' && (data->flags & PREC_FLAGS) == PREC_FLAGS
		&& (unsigned int)data->arg == 0)
		return (0);
	else if (data->conv == 'u')
		putnbr_u_l((unsigned int)data->arg, 10, data);
	else
		print_oct(data);
	return (0);
}

int						print_nums(t_data *data)
{
	if (data->conv == 'd' && (data->flags & PREC_FLAGS) == PREC_FLAGS
			&& data->arg == 0)
		return (0);
	if (data->conv == 'd' && (data->flags & HH_FLAGS) == HH_FLAGS)
		putnbr_l((char)(data->arg), 10, data);
	else if (data->conv == 'd' && (data->flags & H_FLAGS) == H_FLAGS)
		putnbr_l((short)data->arg, 10, data);
	else if (data->conv == 'd' && (data->flags & LL_FLAGS) == LL_FLAGS)
		putnbr_l((long long)data->arg, 10, data);
	else if (data->conv == 'd' && (data->flags & L_FLAGS) == L_FLAGS)
		putnbr_l((long)data->arg, 10, data);
	else if (data->conv == 'd')
		putnbr_l((int)data->arg, 10, data);
	else
		print_un(data);
	return (0);
}
