/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding_nul.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/19 10:40:24 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/02 16:07:40 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			padding_d(t_data *data)
{
	int		lft;

	lft = data->width - data->arg_length;
	if (data->arg_neg != 0 && (data->flags & PMIN_FLAGS) != PMIN_FLAGS)
	{
		ft_putchar_ret('-', data);
		data->flags |= PMIN_FLAGS;
	}
	else if ((data->flags & PLUS_FLAGS) == PLUS_FLAGS && data->arg_neg == 0)
		ft_putchar_ret('+', data);
	else if ((data->flags & SPACE_FLAGS) == SPACE_FLAGS)
		ft_putchar_ret(' ', data);
	if ((int)data->arg == 0 && (data->flags & NULL_FLAGS) != NULL_FLAGS)
		lft--;
	while (lft > 0)
	{
		ft_putchar_ret('0', data);
		lft--;
	}
	return (0);
}

static int			padding_f(t_data *data)
{
	int		lft;

	lft = data->width - data->arg_length;
	if (data->arg_neg != 0 && (data->flags & PMIN_FLAGS) != PMIN_FLAGS)
	{
		ft_putchar_ret('-', data);
		data->flags |= PMIN_FLAGS;
	}
	if ((data->flags & PLUS_FLAGS) == PLUS_FLAGS && data->arg_neg == 0)
		ft_putchar_ret('+', data);
	while (lft > 0)
	{
		ft_putchar_ret('0', data);
		lft--;
	}
	return (0);
}

static void			padding_ton2(t_data *data)
{
	if (data->conv == 'd' && (data->flags & NULL_FLAGS) == NULL_FLAGS &&
		(data->flags & MIN_FLAGS) != MIN_FLAGS)
		padding_d(data);
	else
		padding_all(data);
}

int					padding_oux(t_data *data)
{
	int		lft;

	lft = data->width - data->arg_length;
	while (lft > 0)
	{
		ft_putchar_ret('0', data);
		lft--;
	}
	return (0);
}

void				padding_ton(t_data *data)
{
	if ((data->flags & NULL_FLAGS) == NULL_FLAGS && (data->flags & HASH_FLAGS)
		== HASH_FLAGS && (data->flags & MIN_FLAGS) != MIN_FLAGS && data->prec
		!= 0 && ft_strchr("xX", data->conv))
		print_xo_flags(data);
	if ((data->flags & NULL_FLAGS) == NULL_FLAGS && data->conv == 'f')
		padding_f(data);
	else if (ft_strchr("xX", data->conv) && (data->flags & NULL_FLAGS)
		== NULL_FLAGS && (data->flags & PREC_FLAGS) != PREC_FLAGS &&
		(data->flags & MIN_FLAGS) != MIN_FLAGS)
		padding_oux(data);
	else if (data->conv == 'o' && (data->flags & NULL_FLAGS) == NULL_FLAGS
		&& (data->flags & PREC_FLAGS) != PREC_FLAGS &&
		(data->flags & MIN_FLAGS) != MIN_FLAGS)
		padding_oux(data);
	else if (data->conv == 'u' && (data->flags & NULL_FLAGS) == NULL_FLAGS
		&& (data->flags & PREC_FLAGS) != PREC_FLAGS &&
		(data->flags & MIN_FLAGS) != MIN_FLAGS)
		padding_oux(data);
	else if (data->conv == '%' && (data->flags & NULL_FLAGS) == NULL_FLAGS &&
			(data->flags & MIN_FLAGS) != MIN_FLAGS)
		padding_oux(data);
	else
		padding_ton2(data);
}
