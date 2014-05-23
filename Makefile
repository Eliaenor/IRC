
SRCS =	main.c init_env.c x.c main_loop.c \
		srv_create.c srv_accept.c \
		client_read.c client_write.c

OBJS = ${SRCS:.c=.o}

NAME = bircd

CFLAGS = -I. -g3 -Wall -Werror -Wextra
LDFLAGS = 

CC = gcc
RM = rm -f

${NAME}:	${OBJS}
		${CC} -o ${NAME} ${OBJS} ${LDFLAGS}

all:		${NAME}

clean:
		${RM} ${OBJS} *~ #*#

fclean:		clean
		${RM} ${NAME}

re:		fclean all
