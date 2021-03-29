SRCS	= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS	= ${SRCS:.c=.o}

INCS	= includes

NAME	= libft.a

CC		= gcc

LIBC	= ar rcs

CFLAGS	= -Wall -Werror -Wextra -c

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o} -I${INCS}

${NAME}:	${OBJS}
			${LIBC} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re