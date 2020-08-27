SRCS		=	srcs/algorithm.c			\
				srcs/ft_read_board.c		\
				srcs/free_elems.c			\
				srcs/ft_read_first_line.c	\
				srcs/ft_strlen.c

INCLUDES	=	includes/

NAME		=	BSQ

CFLAGS      =   -Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -f

${NAME}:		
				${CC} -o ${NAME} ${CFLAGS} -I${INCLUDES} srcs/main.c ${SRCS}

all:			${NAME}

clean:
				${RM} *~
				${RM} *#
				${RM} ./srcs/*~
				${RM} ./srcs/*#
				${RM} ./includes/*~
				${RM} ./includes/*#
				${RM} ./includes/*.gch

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re