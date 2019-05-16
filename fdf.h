/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 18:11:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/16 17:30:32 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include "./minilibx_macos/mlx.h"
#include "./Libft/includes/libft.h"
#include "./Libft/includes/get_next_line.h"
#include "./Printf/ft_printf.h"

#define FALSE 0
#define TRUE 1

#define yellow 0xf8d92b

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125

typedef struct 		s_fdf
{
	void			*mlx_ptr;
	void			*window;
	void			*image;
	int				x;
	int				y;
}					t_fdf;

typedef struct 		s_map
{
	int				height;
	int				width;
	int				**field;
}					t_map;


void	window_display(t_fdf *mlx);

int		main(int ag, char **av);
int     **read_field(char *file, t_map *field);		//change names
int		**set_field(char *file, t_map *field, int y);		//change names
int		**map_error();
int		image_window(t_fdf *mlx);
int		key_press(int key, t_fdf *mlx);
int		mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

#endif