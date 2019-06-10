/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 16:14:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/09 17:00:12 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_minprec(const char *s, int i, int prec, t_data *data)
{
	while (prec > 0)
	{
		ft_putchar_ret(s[i], data);
		i++;
		prec--;
	}
}

static void		ft_putsub(const char *str, t_data *data, int prec)
{
	int		i;
	char	*s;

	s = "(null)";
	i = 0;
	prec = data->arg_length;
	if (!data->arg)
	{
		ft_minprec(s, i, prec, data);
		return ;
	}
	if ((data->flags & PREC_FLAGS) == PREC_FLAGS)
		ft_minprec(str, i, prec, data);
	else
		ft_putstr_ret(str, data);
}

void			ft_putchar_ret(char c, t_data *data)
{
	write(1, &c, 1);
	data->ret++;
}

void			ft_putstr_ret(const char *str, t_data *data)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar_ret(*str, data);
		str++;
	}
}

int				print_chars(t_data *data)
{
	if ((data->flags & NULL_FLAGS) == NULL_FLAGS && data->conv != '%')
		padding_oux(data);
	if (data->conv == 'c')
		ft_putchar_ret((unsigned char)data->arg, data);
	else if (data->conv == '%')
		ft_putchar_ret('%', data);
	else if (data->conv == 's')
		ft_putsub((char*)data->arg, data, data->prec);
	else if (data->conv == 'p')
	{
		ft_putstr_ret("0x", data);
		if (data->arg != 0 || (data->arg == 0 &&
		(data->flags & PREC_FLAGS) != PREC_FLAGS))
			putnbr_u_l(data->arg, 16, data);
	}
	return (0);
}
