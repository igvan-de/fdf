/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 16:20:17 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/15 13:16:13 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		set_null(t_data *data)
{
	if ((data->flags & NULL_FLAGS) == NULL_FLAGS &&
		(data->flags & PREC_FLAGS) == PREC_FLAGS)
		data->flags ^= NULL_FLAGS;
	if ((data->flags & NULL_FLAGS) == NULL_FLAGS &&
		(data->flags & PREC_FLAGS) == PREC_FLAGS && data->conv != '%')
		data->flags ^= NULL_FLAGS;
}

void			zero_struct(t_data *data)
{
	data->flags = 0;
	data->conv = '0';
	data->width = 0;
	data->prec = 6;
	data->fd = 1;
	data->arg_length = 0;
	data->arg_neg = 0;
	data->arg = 0;
	data->arg_d = 0;
	data->arg_ld = 0;
	data->numsize = 0;
}

int				check_conv(const char *format, t_data *data)
{
	while (ft_strchr(FLAGS, *format))
		format++;
	if (!ft_strchr(CONVS, *format))
		return (0);
	data->conv = *format;
	if (data->conv == 'i')
		data->conv = 'd';
	if (data->conv == 'C')
		data->conv = 'c';
	if (data->conv == 'D')
	{
		data->conv = 'd';
		data->flags |= L_FLAGS;
	}
	if (data->conv == 'O')
		data->conv = 'o';
	if (data->conv == 'U')
		data->conv = 'u';
	if (data->conv == 'S')
		data->conv = 's';
	if (data->conv == 'F')
		data->conv = 'f';
	return (1);
}

void			check_prec_width(const char *format, t_data *data)
{
	while (ft_strchr(FLAGS, *format) && *format)
	{
		if (*format >= '0' && *format <= '9')
		{
			data->width = ft_atoi(format);
			while (*format >= '0' && *format <= '9')
				format++;
		}
		if (*format == '.' && *(format + 1) >= '0' && *(format + 1) <= '9')
		{
			format++;
			data->prec = ft_atoi(format);
			data->flags |= PREC_FLAGS;
			set_null(data);
			while (*format >= '0' && *format <= '9')
				format++;
		}
		if (*format == '.' && (*(format + 1) < '0' || *(format + 1) > '9'))
		{
			data->prec = 0;
			data->flags |= PREC_FLAGS;
			set_null(data);
		}
		format++;
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	lst;
	t_data	data;

	data.ret = 0;
	va_start(lst, format);
	zero_struct(&data);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				continue;
			arg_handler(format, lst, &data);
			while (ft_strchr(FLAGS, *format) && *format != '\0')
				format++;
		}
		else if (*format != '\0')
			ft_putchar_ret(*format, &data);
		if (*format == '\0')
			break ;
		format++;
	}
	va_end(lst);
	return (data.ret);
}
