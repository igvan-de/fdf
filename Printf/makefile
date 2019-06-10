# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/08 15:22:39 by igvan-de       #+#    #+#                 #
#    Updated: 2019/05/16 17:04:59 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a  
FLAGS = -Wall -Werror -Wextra 
SRC = putnbr_base.c putfl_base.c divide.c divide_fl.c print.c print_char.c \
		length.c itoa_float.c padding_nul.c padding.c flags.c get.c handler.c \
		ft_printf.c print_hex.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I .
	@cp .././Libft/libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
