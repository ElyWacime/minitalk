CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_CFILES = ./ft_printf/ft_printf.c ./ft_printf/ft_utils.c ./ft_printf/ft_utils2.c ./ft_printf/ft_utils3.c
PRINTF_OBJ = $(PRINTF_CFILES:.c=.o)
PRINTF_NAME = libftprintf.a
SERVER_CFILES = server.c server_main.c
CLIENT_CFILES = client.c
CLIENT_OBJ = $(CLIENT_CFILES:.c=.o)
SERVER_OBJ = $(SERVER_CFILES:.c=.o)
SERVER_NAME = server.a
CLIENT_NAME = client.a
SERVER_PROG = server
CLIENT_PROG = client


all: ${PRINTF_NAME} ${SERVER_NAME} ${SERVER_PROG}\
		${CLIENT_NAME} ${CLIENT_PROG}

${PRINTF_NAME}: ${PRINTF_OBJ}
	ar rcs ${PRINTF_NAME} ${PRINTF_OBJ}

${SERVER_NAME} : ${SERVER_OBJ} ${PRINTF_NAME}
	ar rcs ${SERVER_NAME} ${SERVER_OBJ}

${CLIENT_NAME} : ${CLIENT_OBJ} ${PRINTF_NAME}
	ar rcs ${CLIENT_NAME} ${CLIENT_OBJ}

${CLIENT_PROG} : ${PRINTF_NAME} ${CLIENT_NAME}
	gcc ${PRINTF_NAME} ${CLIENT_NAME} -o ${CLIENT_PROG}

${SERVER_PROG} : ${PRINTF_NAME} ${SERVER_NAME}
	gcc ${PRINTF_NAME} ${SERVER_NAME} -o ${SERVER_PROG}

clean:
	rm -rf ${PRINTF_OBJ} ${SERVER_OBJ} ${CLIENT_OBJ}

fclean: clean
	rm -rf ${SERVER_PROG} ${CLIENT_PROG}\
			${PRINTF_NAME} ${SERVER_NAME} ${CLIENT_NAME}

re: fclean all