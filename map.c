/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 15:11:06 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/09 15:13:38 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static int		**atoi_array(int x, int y, char **tab, t_map *map)
{
	while (x > 0)
	{
		x--;
		map->map[y][x] = ft_atoi(tab[x]);
	}
	return(map->map);
}

static int		**check_map(t_map *map, int x)
{
	if (map->width == 0)
		map->width = x;
	if (x != map->width)
		return (map_error());
	return (0);
}

static int		**twodimencional_array(int fd, t_map *map, int y, int x)
{
	char	*line;
	char	**tab;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line == '\0')
			return (map->map);
		tab = ft_strsplit(line, ' ');
		x = ft_arraylen(tab);
		check_map(map, x);
		map->map[y] = (int*)ft_memalloc(sizeof(int) * x);
		atoi_array(x, y, tab, map);
		free(line);
		ft_strarrdel(&tab);
		y++;
		if (ret == -1)
			break ;
	}
	return (map->map);
}

static int		**read_map(char *file, t_map *map, int y)
{
	int		fd;
	int		x;

	x = 0;
	map->map = (int**)ft_memalloc(sizeof(int*) * y);
	y = 0;
	fd = open(file, O_RDONLY);
	twodimencional_array(fd, map, y, x);
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
