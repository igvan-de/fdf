/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/09 18:11:20 by igvan-de       #+#    #+#                */
/*   Updated: 2019/06/05 19:11:23 by igvan-de      ########   odam.nl         */
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
#define ORANGE 0xf98c1f
#define BLUE 0x469DFF
#define GREEN 0x50df20

#define WIDTH 1250
#define HEIGHT 800

#define KEY_ESC 53
#define KEY_UP 126
#define KEY_LEFT 123
#define KEY_RIGHT 124
#define KEY_DOWN 125
#define ROTATE_UP 13		//changed with left button
#define ROTATE_LEFT 0
#define ROTATE_RIGHT 2	//changed with right button
#define ROTATE_DOWN 1
#define R 15
#define PLUS 69
#define MIN 78
#define Z_LEFT 6
#define Z_RIGHT 7

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
	int				z;
	int				delta_x;
	int				delta_y;
	int				color;
	int				z_value;
	double			alpha;
	double			beta;
	double			gamma;
}					t_point;

typedef struct 		s_fdf
{
	void			*mlx_ptr;
	void			*window;
	void			*image;
	int				placement;
	int				x;
	int				y;
	int				increase;
	t_map			*map;
	t_point			*point;
}					t_fdf;

void		window_display(t_fdf *mlx);

int			main(int ag, char **av);
int     	**set_map(char *file, t_map *field);
int			**map_error();
int			put_input(void);
int			put_pixel(int x, int y, t_fdf *mlx);
int			image_window(t_fdf *mlx);
int			key_press(int key, t_fdf *mlx);
int			draw_grid(t_fdf *mlx);
int			set_color(int z, t_fdf *mlx);
int			get_color(t_point current, t_point a, t_point b, t_fdf *mlx);

t_point     rotation_x(t_point cordinate, t_fdf *mlx);
t_point     rotation_y(t_point cordinate, t_fdf *mlx);
t_point     rotation_z(t_point cordinate, t_fdf *mlx);
#endif