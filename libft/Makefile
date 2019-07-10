# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 14:51:14 by acalandr          #+#    #+#              #
#    Updated: 2019/04/15 14:51:19 by acalandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror
MF = *.c
OMF = $(MF:.c=.o)

all: $(NAME)

$(NAME): $(MF)
	@gcc $(FLAGS) -c $?
	@ar rc $(NAME) $(OMF)

clean:
	@rm -f $(OMF)

fclean: clean
	@rm -f $(NAME)

re: fclean all
