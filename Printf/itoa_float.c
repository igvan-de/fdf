/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa_float.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 16:22:07 by wvan-dam       #+#    #+#                */
/*   Updated: 2019/05/02 14:40:37 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*loop(long long n, int size)
{
	char *str;

	if (size == 0)
		size++;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[size] = '\0';
	size--;
	while (n > 0)
	{
		str[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

char		*float_itoa(long long n)
{
	int			size;
	long long	i;

	size = 0;
	i = n;
	while (i > 0)
	{
		i = i / 10;
		size++;
	}
	return (loop(n, size));
}
