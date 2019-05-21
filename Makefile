# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/09 17:46:17 by igvan-de       #+#    #+#                 #
#    Updated: 2019/05/21 15:26:39 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

COLOR_GREEN = $(shell printf "\e[38;5;10m")
COLOR_DEFAULT = $(shell printf "\e[39m")

BINARY = fdf
SRCS = field.c error.c window.c main.c image.c keyboard.c linedrawing.c
OBJ = $(SRCS:%.c=%.o)
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
LIB = Printf/libftprintf.a
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1
PRINT_PLUS = $(shell printf '$(COLOR_GREEN)[ + ]$(COLOR_DEFAULT)')

all: $(BINARY)

$(BINARY):
	@make -C minilibx_macos > /dev/null
	@make -C Libft
	@make -C Printf
	@gcc -g $(FLAGS) -I/usr/X11/includes $(SRCS) $(LIB)
	@echo "$(PRINT_PLUS) Compiling completed"

clean:
	@rm -f $(OBJ)
	@make -C ./Libft clean && make -C ./Printf clean
	@echo "$(PRINT_PLUS) Cleaning objectives completed"

fclean: clean
	@rm -f $(BINARY)
	@make -C ./Libft fclean && make -C ./Printf fclean
	@echo "$(PRINT_PLUS) Cleaning all completed"

re: fclean all
	@echo "$(PRINT_PLUS) Recompiling completed"

norm:
	@echo "===================NORMINETTE==================="
	@$(NORM) || echo "no norminette errors"
	@echo "================================================"