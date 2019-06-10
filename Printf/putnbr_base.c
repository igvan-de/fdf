/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   putnbr_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/03 19:42:47 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/02 13:49:02 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			putnbr_l(long long n, int base, t_data *data)
{
	unsigned long long nb;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	if (nb > 9)
	{
		putnbr_l((nb / base), base, data);
		if ((nb % base) >= 10)
			ft_putchar_ret((nb % base) - 10 + 'a', data);
		else
			putnbr_l((nb % base), base, data);
	}
	else
		ft_putchar_ret((nb % base) + '0', data);
}

void			putnbr_u_l(unsigned long long nb, int base, t_data *data)
{
	if (nb > (unsigned long long)base - 1)
		putnbr_u_l((nb / base), base, data);
	if ((nb % base) >= 10)
	{
		ft_putchar_ret((nb % base) - 10 + 'a', data);
	}
	else
		ft_putchar_ret((nb % base) + '0', data);
}

void			putnbr_u_l_cap(unsigned long long nb, int base, t_data *data)
{
	if (nb > (unsigned long long)base - 1)
	{
		putnbr_u_l_cap((nb / base), base, data);
	}
	if ((nb % base) >= 10)
		ft_putchar_ret((nb % base) - 10 + 'A', data);
	else
		ft_putchar_ret((nb % base) + '0', data);
}
