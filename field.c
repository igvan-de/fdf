/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 11:55:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/16 14:23:12 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		**set_field(char *file, t_map *field)
{
	char	*line;
	char	**tab;
	int		**map;
	int		x;
	int		y;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line == '\0')
			return (0);
		free(line);
		if (ret == 1)
			y++;
		if (ret == -1)
			break ;
	}
	close(fd);
	ret = 1;
	fd = open(file, O_RDONLY);
	map = (int**)ft_memalloc(sizeof(int*) * y);
	while (ret > 0)
    {
        ret = get_next_line(fd, &line);
        tab = ft_strsplit(line, ' ');
        x = ft_arraylen(tab);
        if (field->width == 0)
            field->width = x;
        if (x != field->width)
            return (map_error());
		map[y] = (int*)ft_memalloc(sizeof(int) * x);
		while (x > 0)
        {
       		x--;
			map[y][x] = ft_atoi(tab[x]);
		}
		free(line);
        if (ret == -1)
            break ;
    }
	return (field);
}

	// while (ret > 0)
	// {
	// 	ret = get_next_line(fd, &line);
	// 	x_as = ft_strsplit(line, ' ');
	// 	tab = ft_strlen(*x_as);
	// 	field->width = ft_atoi(tab);
	// 	free(line);
	// 	if (ret == -1)
	// 		break ;
	// }
		// if (!map_error(first_line, len_lines))
		// 	return (FALSE);