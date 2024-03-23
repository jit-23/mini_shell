# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 21:29:48 by fde-jesu          #+#    #+#              #
#    Updated: 2024/03/04 21:21:27 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Werror -Wextra

FUN = $(wildcard *.c)

OBJ = ${FUN:.c=.o}

all: $(NAME)

$(NAME):
	    cc ${CFLAGS} -c ${HEADER} ${FUN}
		ar rc ${NAME} ${OBJ}
clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)
      
re: fclean all

.PHONY: all clean fclean re
.SILENT: