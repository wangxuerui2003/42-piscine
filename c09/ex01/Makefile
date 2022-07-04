NAME	= libft.a

CC		= gcc

AR		= ar

SRCS_D	= ./srcs/

HEADER	= ./includes/

CFLAGS	= -Wall -Wextra -Werror

ARFLAGS	= rc

RAN		= ranlib

SRCS	= ${SRCS_D}ft_putchar.c ${SRCS_D}ft_putstr.c ${SRCS_D}ft_swap.c ${SRCS_D}ft_strlen.c ${SRCS_D}ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

all:	${NAME}

.c.o:
		${CC} ${CFLAGS} -c -I ${HEADER} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS}
			${RAN} ${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:	fclean all
