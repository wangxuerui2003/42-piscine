SRCS	= functions.c ft_hexdump.c functions2.c default_option.c c_option.c

HEADERS	= hexdump.h

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

NAME	= ft_hexdump

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

all:	${OBJS}
		${CC} ${CFLAGS} ${OBJS}
		mv a.out ${NAME}

clean:
		rm -f *.o

fclean:	clean
		rm -f ${NAME}
