SRCFOLD =	./srcs/

HEADFOLD=	./includes/

SRCS	=	${SRCFOLD}ft_convert_base.c		\
			${SRCFOLD}ft_str.c				\
			${SRCFOLD}main.c				\
			${SRCFOLD}s_buff.c				\
			${SRCFOLD}write_line.c			\
			${SRCFOLD}files.c				\
			${SRCFOLD}read0.c

HEADER	=	${HEADFOLD}ft_str.h		\
			${HEADFOLD}hexdump.h	\
			${HEADFOLD}s_buff.h

OBJS	=	${SRCS:.c=.o}

NAME	=	ft_hexdump

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