/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 18:11:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/26 15:16:18 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include "./minilibx_macos/mlx.h"
#include "./Libft/includes/libft.h"
#include "./Libft/includes/get_next_line.h"
#include "./Printf/ft_printf.h"
#include <stdio.h> /* DELETE ME !!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

//check colors I want to use later
#define yellow 0xf8d92b
#define blue 0x469DFF
#define green 0x31D75D

#define WIDTH 1250
#define HEIGHT 800

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125

#define ABS(x) (x) < 0 ? (x) * -1 : (x) ///Create function for this!!!

typedef struct 		s_map
{
	int				height;
	int				width;
	int				**map;
}					t_map;

typedef struct		s_point
{
	int				x;
	int				y;
	int				delta_x;
	int				delta_y;
}					t_point;

typedef struct 		s_fdf
{
	void			*mlx_ptr;
	void			*window;
	void			*image;
	int				placement;
	int				x;
	int				y;
	int				negative;
	t_map			*map;
	t_point			*delta;
}					t_fdf;

void	window_display(t_fdf *mlx);

int 	test(t_fdf *mlx); ////Remove, is only to test!!!

int		main(int ag, char **av);
int     **set_field(char *file, t_map *field);
int		**map_error();
int		put_input(void);
int		image_window(t_fdf *mlx);
int		key_press(int key, t_fdf *mlx);

#endif