/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/28 13:39:22 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/09 17:55:59 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_intcounter(int n)
{
	int			i;
	unsigned	len;

	len = 0;
	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -1 * n;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char		*ft_count(int n)
{
	char		*s;
	int			len;
	unsigned	nb;

	len = ft_intcounter(n);
	s = ft_strnew(len);
	if (n < 0)
	{
		s[0] = '-';
		nb = n * -1;
	}
	else
		nb = n;
	s[len] = '\0';
	len--;
	if (n == 0)
		s[len] = '0';
	while (nb > 0)
	{
		s[len] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char		*s;
	int			len;

	len = ft_intcounter(n);
	s = ft_strnew(len);
	if (s == NULL)
		return (NULL);
	s = ft_count(n);
	return (s);
}
