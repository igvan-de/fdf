/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   field.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 11:55:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/14 18:23:26 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		**set_field(char *file, t_map *field)
{
	char	*line;
	char	*buff;
	int		fd;
	int		ret;
	char	*x;
	char	*y;
	//int		**field;

	ret = 1;
	fd = open(file, O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		buff = ft_strjoin(buff, line);
		y = ft_strsplit(*line, '\n');
		x = ft_strsplit(*line, ' ');
		free(line);
		if (ret == -1)
			break ;
	}
	close(fd);
	return (field);
}

		// if (!map_error(first_line, len_lines))
		// 	return (FALSE);
