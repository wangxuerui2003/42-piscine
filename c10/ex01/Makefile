SRCS	= functions.c ft_cat.c

HEADERS	= cat.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= ft_cat

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

all:	${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		rm -f *.o

fclean:	clean
		rm -f ${NAME}
