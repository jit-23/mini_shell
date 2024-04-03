NAME:= minishell
#CFLAGS:= -Wall -Wextra -Werror
HEADER:= minishell.h
RM:= rm -f

#TAKE THIS OFF
#FUN:= $(wildcard src/*.c)
FUN:= src/main.c \
			src/analise_cmd_size.c \
			src/utils.c	\
			src/exec_single_cmd.c \
			src/exec_complex_cmd.c \
			src/parsing.c \
			
OBJ:= ${patsubst %.c, %.o, ${FUN}}

MAKE:= make -C

LIBFT_DIR:= includes/libft
LIBFT:= includes/libft/libft.a
all: ${OBJ} ${NAME}

${NAME}:
	${MAKE} ${LIBFT_DIR} 
	cc -I. ${FUN} ${LIBFT} -o ${NAME} -lreadline 

clean:
	${RM} ${OBJ}
	${MAKE} ${LIBFT_DIR} clean

fclean: clean
	${RM} ${NAME}
	${MAKE} ${LIBFT_DIR} fclean

re: fclean all
.PHONY: fclean clean all re





#NAME:= minishell
##CFLAGS:= -Wall -Wextra -Werror
#HEADER:= minishell.h
#RM:= rm -f
#
##TAKE THIS OFF
##FUN:= $(wildcard src/*.c)
#FUN:= src/main.c \
#			src/analise_cmd_size.c \
#			src/utils.c	\
#			src/exec_single_cmd.c \
#			src/exec_complex_cmd.c \
#			src/parsing.c \
#			
#OBJ:= ${patsubst %.c, %.o, ${FUN}}
#
#MAKE:= make -C
#
#PIPEX_DIR:= includes/pipex
#PIPEX:= includes/pipex/pipex.a
#LIBFT:= includes/pipex/libft/libft.a
#all: ${OBJ} ${NAME}
#
#${NAME}:
#	${MAKE} ${PIPEX_DIR}
#	cc -I. ${FUN} ${PIPEX} ${LIBFT} -o ${NAME} -lreadline 
## ${CFLAGS}
#
#clean:
#	${RM} ${OBJ}
#	${MAKE} ${PIPEX_DIR} clean
#
#fclean: clean
#	${RM} ${NAME}
#	${MAKE} ${PIPEX_DIR} fclean
#
#re: fclean all
#.PHONY: fclean clean all re
#