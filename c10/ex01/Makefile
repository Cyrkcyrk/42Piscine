SRCFOLD =	./srcs/

HEADFOLD=	./includes/

SRCS	=	${SRCFOLD}ft_strlen.c		\
			${SRCFOLD}main.c

OBJS	=	${SRCS:.c=.o}

NAME	=	ft_cat

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADFOLD}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -I ${HEADFOLD}

all:		${NAME}

clean:
			${RM} ${OBJS}
			find . -type f \( -name "#*" -o -name "*~" -o -name "*#" \) -print -delete

fclean:		clean
			${RM} ${NAME}

re:			fclean all