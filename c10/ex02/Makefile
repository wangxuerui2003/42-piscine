SRCS	= functions.c ft_tail.c functions2.c c_option.c cnum_option.c

HEADERS	= tail.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= ft_tail

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

all:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
		rm -f *.o

fclean:	clean
		rm -f ${NAME}
