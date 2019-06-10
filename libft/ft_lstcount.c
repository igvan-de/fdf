/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstcount.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 15:47:37 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/09 17:55:59 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_lstcount(t_list **alst)
{
	t_list	*temp;
	int		c;

	c = 0;
	temp = *alst;
	if (!alst)
		return (0);
	while (temp != NULL)
	{
		c++;
		temp = temp->next;
	}
	return (c);
}
