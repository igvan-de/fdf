/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 11:55:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/10 13:23:10 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int     main(int ag, char **av)
{
    char    *line;
    int     ret;
    int     fd;

    ret = 1;
    fd = open(av[1], O_RDONLY);
    if (ag != 2)
        return (FALSE);
    while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        free(line);
        if (ret == -1)
            break;
    }
    return (0);
}