/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 15:11:06 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/03 11:46:07 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int		**read_map(char *file, t_map *map, int y)
{
	char	*line;
	char	**tab;
	int		fd;
	int		x;
	int		ret;

	x = 0;
	ret = 1;
	map->map = (int**)ft_memalloc(sizeof(int*) * y);
	y = 0;
	fd = open(file, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line == '\0')
			return (map->map);
		tab = ft_strsplit(line, ' ');
		x = ft_arraylen(tab);
		if (map->width == 0)
			map->width = x;
		if (x != map->width)
			return (map_error());
		map->map[y] = (int*)ft_memalloc(sizeof(int) * x);
		while (x > 0)
		{
			x--;
			map->map[y][x] = ft_atoi(tab[x]);
		}
		free(line);
		y++;
		if (ret == -1)
			break ;
	}
	close(fd);
	return (map->map);
}

int				**set_map(char *file, t_map *map)
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
	map->height = y;
	return (read_map(file, map, y));
}
