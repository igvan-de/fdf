/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/24 10:49:45 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/09 17:02:29 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_star(const char *format, va_list lst)
{
	if (*format == '*')
		va_arg(lst, int);
}

void		check_flags(const char *format, va_list lst, t_data *data)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == 'l' && (data->flags & L_FLAGS) == L_FLAGS)
			data->flags |= LL_FLAGS;
		else if (*format == 'l')
			data->flags |= L_FLAGS;
		if (*format == 'h' && (data->flags & H_FLAGS) == H_FLAGS)
			data->flags |= HH_FLAGS;
		else if (*format == 'h')
			data->flags |= H_FLAGS;
		if (*format == '#')
			data->flags |= HASH_FLAGS;
		if (*format == 'L')
			data->flags |= CL_FLAGS;
		if (*format == '-')
			data->flags |= MIN_FLAGS;
		if (*format == '+')
			data->flags |= PLUS_FLAGS;
		if (*format == ' ')
			data->flags |= SPACE_FLAGS;
		if (*format == '0' && !ft_strchr("012345789.", *(format - 1)))
			data->flags |= NULL_FLAGS;
		ft_star(format, lst);
		format++;
	}
}

int			print_prec(t_data *data)
{
	int		psize;

	psize = 0;
	if (data->conv == 'o')
		psize = data->prec - data->numsize;
	if (data->conv == 'x' || data->conv == 'X')
		psize = data->prec - data->numsize;
	if (data->conv == 'd')
		psize = data->prec - data->numsize;
	if (data->conv == 'u')
		psize = data->prec - data->numsize;
	if ((data->flags & HASH_FLAGS) == HASH_FLAGS && data->conv == 'o')
		psize -= 1;
	while (psize > 0)
	{
		ft_putchar_ret('0', data);
		psize--;
	}
	return (data->width);
}

int			print_xo_flags(t_data *data)
{
	if (data->conv == 'o' &&
		(data->flags & HASH_FLAGS) == HASH_FLAGS)
		ft_putchar_ret('0', data);
	if (data->conv == 'x' && data->arg != 0 &&
		(data->flags & HASH_FLAGS) == HASH_FLAGS)
	{
		ft_putchar_ret('0', data);
		ft_putchar_ret('x', data);
	}
	if (data->conv == 'X' && data->arg != 0 &&
		(data->flags & HASH_FLAGS) == HASH_FLAGS)
	{
		ft_putchar_ret('0', data);
		ft_putchar_ret('X', data);
	}
	return (0);
}

int			print_flags(t_data *data)
{
	if (data->conv == 'd' && data->arg_neg == 0 &&
		(data->flags & SPACE_FLAGS) == SPACE_FLAGS && (data->flags & PLUS_FLAGS)
		!= PLUS_FLAGS && (data->flags & NULL_FLAGS) != NULL_FLAGS)
		ft_putchar_ret(' ', data);
	if (data->conv == 'd' && (data->flags & PLUS_FLAGS) == PLUS_FLAGS
		&& data->arg_neg == 0 && (data->flags & NULL_FLAGS) != NULL_FLAGS)
		ft_putchar_ret('+', data);
	if (data->conv == 'd' && data->arg_neg == 1 && (data->flags & NULL_FLAGS)
		== NULL_FLAGS && (data->flags & PMIN_FLAGS) != PMIN_FLAGS)
		ft_putchar_ret('-', data);
	if (data->arg_neg == 1 && (data->flags & NULL_FLAGS) != NULL_FLAGS
		&& (data->flags & PMIN_FLAGS) != PMIN_FLAGS)
	{
		ft_putchar_ret('-', data);
		data->flags |= PMIN_FLAGS;
	}
	return (0);
}
