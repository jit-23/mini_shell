NAME:= minishell
CFLAGS:= -Wall -Wextra -Werror
RM:= rm -f

FUN:= $(wildcard src/*.c)
OBJ:= ${patsubst %.c, %.o, ${FUN}}

MAKE:= make -C

PIPEX_DIR:= includes/pipex
PIPEX:= includes/pipex/pipex

all: ${OBJ} ${NAME}

${NAME}:
	${MAKE} ${PIPEX_DIR}
	cc ${CFLAGS} -I. ${FUN} ${PIPEX} -o ${NAME}

clean:
	${RM} ${OBJ}
	${MAKE} ${PIPEX_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} ${PIPEX_DIR} fclean

re: fclean all
.PHONY: fclean clean all re
