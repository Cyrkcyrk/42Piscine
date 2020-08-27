
SRCFOLD =	./srcs/

HEADFOLD=	./includes/

SRCS	=	${SRCFOLD}check_dic.c			\
			${SRCFOLD}ck_dict.c				\
			${SRCFOLD}ft_free.c				\
			${SRCFOLD}ck_files.c			\
			${SRCFOLD}ck_ft_split.c			\
			${SRCFOLD}ck_parse_key_str.c	\
			${SRCFOLD}ck_parse_line.c		\
			${SRCFOLD}create_triplets.c		\
			${SRCFOLD}display_triplets.c	\
			${SRCFOLD}ft_atoi.c				\
			${SRCFOLD}ft_putchar.c			\
			${SRCFOLD}ft_putstr.c			\
			${SRCFOLD}ft_strdup.c			\
			${SRCFOLD}ft_strlen.c			\
			${SRCFOLD}main.c

OBJS	=	${SRCS:.c=.o}

NAME	=	rush-02

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
