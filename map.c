/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 15:11:06 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/24 17:22:31 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int		**read_field(char *file, t_map *field, int y)
{
	char	*line;
	char	**tab;
	int		fd;
	int		x;
	int		ret;

	x = 0;
	ret = 1;
	field->map = (int**)ft_memalloc(sizeof(int*) * y);
	fd = open(file, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line == '\0')
			return (field->map);
		tab = ft_strsplit(line, ' ');
		x = ft_arraylen(tab);
		if (field->width == 0)
			field->width = x;
		if (x != field->width)
			return (map_error());
		field->map[y] = (int*)ft_memalloc(sizeof(int) * x);
		while (x > 0)
		{
			x--;
			field->map[y][x] = ft_atoi(tab[x]);
		}
		free(line);
		if (ret == -1)
			break ;
	}
	close(fd);
	return (field->map);
}

int				**set_field(char *file, t_map *field)
{
	char	*line;
	int		y;
	int		fd;
	int		ret;

	ret = 1;
	y = 0;
	fd = open(file, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		free(line);
		if (ret == 1)
			y++;
		if (ret == -1)
			break ;
	}
	close(fd);
	field->height = y;
	return (read_field(file, field, y));
}
