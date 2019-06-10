/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/25 14:15:09 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/16 14:12:16 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include ".././Libft/includes/libft.h"

# define H_FLAGS (1 << 0)
# define L_FLAGS (1 << 1)
# define HH_FLAGS (1 << 2)
# define LL_FLAGS (1 << 3)
# define HASH_FLAGS (1 << 4)
# define NULL_FLAGS (1 << 5)
# define MIN_FLAGS (1 << 6)
# define PLUS_FLAGS (1 << 7)
# define SPACE_FLAGS (1 << 8)
# define CL_FLAGS (1 << 9)
# define PREC_FLAGS (1 << 10)
# define PMIN_FLAGS (1 << 11)

# define CONVS "dDiufFoxXcCsSpbUO%"
# define FLAGS "lh.-+#* L0123456789zj"

typedef struct			s_data
{
	unsigned long long	arg;
	double				arg_d;
	long double			arg_ld;
	int					arg_neg;
	int					arg_length;
	unsigned short		flags;
	char				conv;
	int					width;
	int					prec;
	int					fd;
	long long			ret;
	int					numsize;
	int					psize;
}						t_data;

int						divide_f_ld(long double flo, t_data *data);
int						divide_f_d(double flo, t_data *data);
int						divide_o(unsigned long long posneg, t_data *data);
int						divide_hex(unsigned long long posneg, t_data *data);
int						divide_l_l(long long posneg, t_data *data);
int						divide_u_l_l(unsigned long long pos, t_data *data);
int						get_d_length(t_data *data);
int						get_o_length(t_data *data);
int						get_x_length(t_data *data);
int						get_u_length(t_data *data);
int						ft_printf(const char *format, ...);
int						print_floats(t_data *data);
int						print_chars(t_data *data);
int						print_nums(t_data *data);
int						print_xo_flags(t_data *data);
int						print_flags(t_data *data);
int						print_prec(t_data *data);
int						print_handler(t_data *data);
int						padding_oux(t_data *data);
int						padding_all(t_data *data);
int						get_arg(va_list lst, t_data *data);
int						get_neg(t_data *data);
int						get_length(t_data *data);
int						arg_handler(const char *format, va_list lst,
						t_data *data);
int						print_hex(t_data *data);
int						check_conv(const char *format, t_data *data);

void					padding_ton(t_data *data);
void					putnbr_l(long long nb, int base, t_data *data);
void					putnbr_u_l(unsigned long long nb, int base,
						t_data *data);
void					putnbr_u_l_cap(unsigned long long nb, int base,
						t_data *data);
void					ftoa(double nb, int precision, t_data *data);
void					ftoa_long(long double nb, int precision, t_data *data);
void					check_flags(const char *format, va_list lst,
						t_data *data);
void					check_prec_width(const char *format, t_data *data);
void					zero_struct(t_data *data);
void					ft_putchar_ret(char c, t_data *data);
void					ft_putstr_ret(const char *str, t_data *data);

char					*float_itoa(long long n);

#endif
