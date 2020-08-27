SRCFOLD =	./srcs/

SRCS	=	${SRCFOLD}main.c

OBJS	=	${SRCS:.c=.o}

NAME	=	ft_display_file

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			find . -type f \( -name "#*" -o -name "*~" -o -name "*#" \) -print -delete

fclean:		clean
			${RM} ${NAME}

re:			fclean all