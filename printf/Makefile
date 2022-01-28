NAME     = libftprintf.a

CC     = gcc

LINKER     = ar rcs

RM     = rm -rf

SRCS    = libftprintf.c libftprintf_utils.c convertion_hexa.c convertion_u.c convertion_p.c\

OBJS        = ${SRCS:.c=.o}

CFLAGS     = -Wall -Wextra -Werror

$(NAME): ${OBJS}
	${LINKER} ${NAME} ${OBJS}

all:    ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re:    fclean all

.PHONY:	all clean fclean re
