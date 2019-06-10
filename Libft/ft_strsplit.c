/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 16:32:59 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/16 13:41:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_wordcount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 1;
	while (s[i] == c)
		i++;
	if (s[i] == '\0')
		return (count - 1);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			count++;
		}
		else
			i++;
	}
	if (s[i - 1] == c)
		count--;
	return (count);
}

static int		ft_wordlength(char const *s, char c, unsigned int k)
{
	unsigned int	i;

	i = 0;
	while (s[k] != c && s[k] != '\0')
	{
		k++;
		i++;
	}
	return (i);
}

static int		ft_arrsplit(char const *s, char c, char **str)
{
	int				i;
	int				k;
	int				b;

	k = 0;
	b = 0;
	while (b < (ft_wordcount(s, c)))
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		str[b] = (char*)ft_memalloc(sizeof(char) * (ft_wordlength(s, c, k) + 1));
		if (str[b] == NULL)
			return (0);
		i = 0;
		while (s[k] != c && s[k])
		{
			str[b][i] = s[k];
			i++;
			k++;
		}
		str[b][i] = '\0';
		b++;
	}
	str[b] = NULL;
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int				res;
	char			**str;

	if (!s)
		return (NULL);
	str = (char**)ft_memalloc(sizeof(char*) * (ft_wordcount(s, c) + 1));
	if (str == NULL)
		return (NULL);
	res = ft_arrsplit(s, c, str);
	if (res == 0)
		return (NULL);
	return (str);
}
