/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 11:55:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/13 18:03:26 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

void		x_y_calculate(char *line, t_fdf *mlx)
{
	mlx->y = ft_strsplit(mlx->y, '\n');
	mlx->x = ft_strsplit(mlx->x, ' ');
	ft_printf("y = %d\n", mlx->x);
	ft_printf("x = %d\n", mlx->x);
}

int		read_fd(char *file, t_fdf *mlx)
{
	char	*line;
	int		ret;
	int		fd;
	int		len_lines;
	int		first_line;

	ret = 1;
	len_lines = 0;
	fd = open(file, O_RDONLY);
	ret = get_next_line(fd, &line);
	first_line = ft_strlen(line);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line == '\0')
			return (TRUE);
		len_lines = ft_strlen(line);
		if (!map_error(first_line, len_lines))
			return (FALSE);
		x_y_calculate(line, mlx);
		free(line);
		if (ret == -1)
			break ;
	}
	return (TRUE);
}
