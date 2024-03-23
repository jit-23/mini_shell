NAME =  pipex
CFLAGS = -Wall -Werror -Wextra
FUN = src/main.c src/check_args.c src/pipex.c src/free.c
OBJ = ${FUN:.c=.o}
LIBFT = ./libft/libft.a
MAKE = make -C

all: ${OBJ} ${NAME}

${NAME} :
			${MAKE} libft
			cc ${CFLAGS} -I. ${FUN} ${LIBFT}
			ar rc ${NAME}
clean:
	rm -f ${OBJ}
	${MAKE} libft clean

fclean: clean
	rm -f ${NAME}
	${MAKE} libft fclean

re : fclean all

.PHONY: fclean clean re all
