# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 16:58:34 by eescalei          #+#    #+#              #
#    Updated: 2024/04/03 04:24:58 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a
HEADER = lib.h	

all: $(NAME)
	ar -rcs ${NAME} ./libft/libft.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a ${HEADER}

$(NAME):
	make bonus -C ./libft/
	make -C ./ft_printf/
	make -C ./get_next_line/
clean:
	make fclean -C ./libft/
	make fclean -C ./ft_printf/
	make fclean -C ./get_next_line/

fclean: clean
	rm -f $(NAME)
	
re: fclean all
