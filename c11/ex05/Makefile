SRCS	= srcs/main.c srcs/ft_atoi.c srcs/ft_math.c srcs/ft_print.c
OBJS	= ${SRCS:.c=.o}
NAME	= do-op
INCS	= includes
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c
RM		= rm -f

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o} -I${INCS}

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re