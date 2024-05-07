CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_CFILES = ./ft_printf/ft_printf.c ./ft_printf/ft_utils.c ./ft_printf/ft_utils2.c ./ft_printf/ft_utils3.c
PRINTF_OBJ = $(PRINTF_CFILES:.c=.o)
PRINTF_NAME = libftprintf.a
SERVER_CFILES = server.c server_utils.c
CLIENT_CFILES = client.c client_utils.c
CLIENT_OBJ = $(CLIENT_CFILES:.c=.o)
SERVER_OBJ = $(SERVER_CFILES:.c=.o)
SERVER_NAME = server.a
CLIENT_NAME = client.a
SERVER_PROG = server
CLIENT_PROG = client

######## for bonus ########:
SERVERBS_CFILES = ./bonus/server_bonus.c ./bonus/server_utils_bonus.c
CLIENTBS_CFILES = ./bonus/client_bonus.c ./bonus/client_utils_bonus.c
CLIENTBS_OBJ = $(CLIENTBS_CFILES:.c=.o)
SERVERBS_OBJ = $(SERVERBS_CFILES:.c=.o)
SERVERBS_NAME = server_bonus.a
CLIENTBS_NAME = client_bonus.a
SERVERBS_PROG = server_bonus
CLIENTBS_PROG = client_bonus
######## for bonus ########:

all: ${PRINTF_NAME} ${SERVER_NAME} ${SERVER_PROG}\
		${CLIENT_NAME} ${CLIENT_PROG}

bonus: ${PRINTF_NAME} ${SERVERBS_NAME} ${SERVERBS_PROG}\
		${CLIENTBS_NAME} ${CLIENTBS_PROG}

debug:
	gcc ${CFLAGS} -g -fsanitize=address ${PRINTF_CFILES} ${CLIENT_CFILES} -o client_debug
	gcc ${CFLAGS} -g -fsanitize=address ${PRINTF_CFILES} ${SERVER_CFILES} -o server_debug

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

######## for bonus ########:
${SERVERBS_NAME} : ${SERVERBS_OBJ} ${PRINTF_NAME}
	ar rcs ${SERVERBS_NAME} ${SERVERBS_OBJ}

${CLIENTBS_NAME} : ${CLIENTBS_OBJ} ${PRINTF_NAME}
	ar rcs ${CLIENTBS_NAME} ${CLIENTBS_OBJ}

${CLIENTBS_PROG} : ${PRINTF_NAME} ${CLIENTBS_NAME}
	gcc ${PRINTF_NAME} ${CLIENTBS_NAME} -o ${CLIENTBS_PROG}

${SERVERBS_PROG} : ${PRINTF_NAME} ${SERVERBS_NAME}
	gcc ${PRINTF_NAME} ${SERVERBS_NAME} -o ${SERVERBS_PROG}
cleanbs:
	rm -rf ${PRINTF_OBJ} ${SERVERBS_OBJ} ${CLIENTBS_OBJ}

fcleanbs: cleanbs
	rm -rf ${SERVERBS_PROG} ${CLIENTBS_PROG}\
			${PRINTF_NAME} ${SERVERBS_NAME} ${CLIENTBS_NAME}

rebs: cleanbs bonus
######## for bonus ########:

re: fclean all

git:
	git add .
	git commit -m "make commit"