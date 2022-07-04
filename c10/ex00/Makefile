NAME	= ft_display_file

SRCS	= ft_display_file.c functions.c

HEADERS	= ft.h

CFLAGS	= -Wall -Werror -Wextra

CC	= gcc

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
