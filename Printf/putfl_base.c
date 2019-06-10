/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putfl_base.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/23 16:35:16 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/08 16:42:03 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putf(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_ret(str[i], data);
		i++;
	}
}

static void		ft_round(char *str)
{
	int			i;

	i = 0;
	while (str[i + 1])
		i++;
	if (str[i] >= '5')
	{
		i--;
		while (str[i] == '9')
		{
			str[i] = '0';
			i--;
		}
		if (str[i] == '.')
			i--;
		str[i]++;
	}
}

void			ftoa(double nb, int precision, t_data *data)
{
	char		*str;
	double		tmp;

	if ((long long)nb < 0)
		nb *= -1;
	str = ft_itoa((long long)nb);
	if (precision != 0)
		str = ft_strjoin(str, ".");
	tmp = nb;
	while (precision >= 0)
	{
		tmp = tmp - (long long)tmp;
		tmp = tmp * 10;
		str = ft_strjoin(str, float_itoa(tmp));
		precision--;
	}
	ft_round(str);
	str[ft_strlen(str) - 1] = '\0';
	ft_putf(str, data);
}

void			ftoa_long(long double nb, int precision, t_data *data)
{
	char			*str;
	long double		tmp;

	if ((long long)nb < 0)
		nb *= -1;
	str = ft_itoa((long long)nb);
	if (precision != 0)
		str = ft_strjoin(str, ".");
	tmp = nb;
	while (precision >= 0)
	{
		tmp = tmp - (long long)tmp;
		tmp = tmp * 10;
		str = ft_strjoin(str, float_itoa(tmp));
		precision--;
	}
	ft_round(str);
	str[ft_strlen(str) - 1] = '\0';
	ft_putf(str, data);
}
