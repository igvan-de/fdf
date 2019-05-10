# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: igvan-de <igvan-de@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/09 17:46:17 by igvan-de       #+#    #+#                 #
#    Updated: 2019/05/10 18:54:46 by igvan-de      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BINARY = fdf
SRCS = read.c
OBJ = $(SRCS:%.c=%.o)
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
LIB = Libft/Libft.a
NORM = norminette $(SRCS) $(HEADER) | grep -e "Error" -e "Warning" -B 1

all: $(BINARY)

$(BINARY):
	@echo "Compiling in progress..."
	@make -C minilibx_macos > /dev/null && make -C Libft/
	@gcc -g $(FLAGS) -I/usr/X11/includes $(SRCS) $(LIB)
	@echo "Compiling completed"

clean:
	@echo "Cleaning objectives in progress.."
	@rm -f $(OBJ)
	@make -C ./Libft clean
	@echo "Cleaning objectives completed"

fclean: clean
	@echo  "Cleaning all in progress.."
	@rm -f $(BINARY)
	@make -C ./Libft fclean
	@echo "Cleaning all completed"

re: fclean all
	@echo "Recompiling in progress.."
	@echo "Recompiling completed"

norm:
	@echo "===============NORMINETTE==============="
	@$(NORM) || echo "no norminette errors"
	@echo "========================================"