/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wvan-dam <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/02 14:30:49 by wvan-dam      #+#    #+#                 */
/*   Updated: 2019/05/02 14:30:51 by wvan-dam      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_hex2(t_data *data)
{
	if (data->conv == 'X' && (data->flags & LL_FLAGS) == LL_FLAGS)
		putnbr_u_l_cap((unsigned long long)data->arg, 16, data);
	else if (data->conv == 'X' && (data->flags & L_FLAGS) == L_FLAGS)
		putnbr_u_l_cap((unsigned long)data->arg, 16, data);
	else if (data->conv == 'X')
		putnbr_u_l_cap((unsigned int)data->arg, 16, data);
	else
		putnbr_u_l(data->arg, 10, data);
}

int				print_hex(t_data *data)
{
	if (data->conv == 'x' && (data->flags & HH_FLAGS) == HH_FLAGS)
		putnbr_u_l((unsigned char)data->arg, 16, data);
	else if (data->conv == 'x' && (data->flags & H_FLAGS) == H_FLAGS)
		putnbr_u_l((unsigned short)data->arg, 16, data);
	else if (data->conv == 'x' && (data->flags & LL_FLAGS) == LL_FLAGS)
		putnbr_u_l((unsigned long long)data->arg, 16, data);
	else if (data->conv == 'x' && (data->flags & L_FLAGS) == L_FLAGS)
		putnbr_u_l((unsigned long)data->arg, 16, data);
	else if (ft_strchr("xX", data->conv) && (data->flags
		& PREC_FLAGS) == PREC_FLAGS && data->arg == 0 && data->prec == 0)
		return (0);
	else if (data->conv == 'x')
		putnbr_u_l((unsigned int)data->arg, 16, data);
	else if (data->conv == 'X' && (data->flags & HH_FLAGS) == HH_FLAGS)
		putnbr_u_l_cap((unsigned char)data->arg, 16, data);
	else if (data->conv == 'X' && (data->flags & H_FLAGS) == H_FLAGS)
		putnbr_u_l_cap((unsigned short)data->arg, 16, data);
	else
		print_hex2(data);
	return (0);
}
