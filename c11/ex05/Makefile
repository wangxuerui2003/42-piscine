SRCS	= do-op.c functions.c operations.c

HEADERS	= ft.h

OBJS	= ${SRCS:.c=.o}

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= do-op

.c.o:
		${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

all:	${OBJS}
		${CC} ${CFLAGS} ${OBJS}
		mv a.out ${NAME}

clean:
		rm -f *.o

fclean:	clean
		rm -f ${NAME}
