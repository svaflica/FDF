# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/12 17:26:30 by acalandr          #+#    #+#              #
#    Updated: 2019/05/25 16:07:18 by djeanna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Wextra -Werror
INCL1 = /usr/local/include
INCL2 = ./libft
LIB1 = /usr/local/lib/ -lmlx
LIB2 = ./libft/ -lft
SRC = \
		source/main.c \
		source/ft_read.c \
		source/ft_draw_line.c \
		source/quaternion.c \
		source/vector3.c \
		source/rotation.c \
		source/poligonalize.c \
		source/mlx.c \
		source/ft_moving.c \
		source/input.c \
		source/linear_gradient.c \
		source/draw_line_helper.c \
		source/ft_perror.c \
		source/vector3_del.c \
		source/poligonalize_helper.c
OBJ = $(SRC:.c=.o)
FRM1 = OpenGL
FRM2 = AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make re --directory $(INCL2)
	@gcc $(FLAGS) -I $(INCL1) -I $(INCL2) $(OBJ) -L $(LIB1) -L $(LIB2) -framework $(FRM1) -framework $(FRM2) -o $(NAME) -g

source/%.o: source/%.c
	@gcc -I ./include/ -o $@ -c $<

clean:
	@make fclean --directory $(INCL2)
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
