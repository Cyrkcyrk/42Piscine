
SRCFOLD	= 	./srcs/

HEADFOLD= 	./includes/

SRCS	= 	${SRCFOLD}ft_putchar.c	\
			${SRCFOLD}ft_putstr.c	\
			${SRCFOLD}ft_strcmp.c	\
			${SRCFOLD}ft_strlen.c	\
			${SRCFOLD}ft_swap.c

HEADER	=	${HEADFOLD}ft.h

OBJS	= 	${SRCS:.c=.o}

NAME	= 	libft.a

CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${HEADFOLD}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
