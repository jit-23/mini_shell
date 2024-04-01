NAME:= minishell
#CFLAGS:= -Wall -Wextra -Werror
RM:= rm -f

#TAKE THIS OFF
#FUN:= $(wildcard src/*.c)
FUN:= src/main.c \
			src/parsing.c \
			src/utils.c	\
			src/exec_single_cmd.c

OBJ:= ${patsubst %.c, %.o, ${FUN}}

MAKE:= make -C

PIPEX_DIR:= includes/pipex
PIPEX:= includes/pipex/pipex
LIBFT:= includes/pipex/libft/libft.a
all: ${OBJ} ${NAME}

${NAME}:
	${MAKE} ${PIPEX_DIR}
	cc -I. ${FUN} ${PIPEX} ${LIBFT}  -o ${NAME} -lreadline 
# ${CFLAGS}

clean:
	${RM} ${OBJ}
	${MAKE} ${PIPEX_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} ${PIPEX_DIR} fclean

re: fclean all
.PHONY: fclean clean all re


#NAME:= minishell
#CFLAGS:= -Wall -Wextra -Werror
#RM:= rm -f
#
##TAKE THIS OFF
#FUN:= $(wildcard src/*.c)
##TAKE THIS OFF
#OBJ:= ${patsubst %.c, %.o, ${FUN}}
#
#MAKE:= make -C
#
#PIPEX_DIR:= includes/pipex
#PIPEX:= includes/pipex/pipex
#
#	${MAKE} ${PIPEX_DIR}
#LIBFT_DIR:= includes/pipex/libft
#LIBFT:= includes/pipex/libft/libft
#
#
#all: ${OBJ} ${NAME}
#
#${NAME}:
#	${MAKE} ${PIPEX_DIR}
#	${MAKE} ${LIBFT_DIR}
#	cc ${CFLAGS} -I. ${FUN} ${PIPEX} ${LIBFT} -o ${NAME} -lreadline
#
#clean:
#	${RM} ${OBJ}
#	${MAKE} ${PIPEX_DIR} clean
#	${MAKE} ${LIBFT_DIR} clean
#
#fclean: clean
#	${RM} ${NAME}
#	${MAKE} ${PIPEX_DIR} fclean
#	${MAKE} ${LIBFT_DIR} fclean
#
#re: fclean all
#.PHONY: fclean clean all re
##