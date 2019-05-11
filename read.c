/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/10 11:55:46 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/11 16:59:03 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int		read_fd(char *file)
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
		free(line);
		if (ret == -1)
			break ;
	}
	return (TRUE);
}

int		main(int ag, char **av)
{
	t_fdf	*mlx;

	if (ag == 1)
		return (FALSE);
	mlx = (t_fdf*)malloc(sizeof(t_fdf));
	mlx->mlx_ptr = mlx_init();
	read_fd(av[1]);
	window_display(mlx);
	return (0);
}