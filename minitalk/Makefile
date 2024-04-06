# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SERVER = server.c
# BONUS_SERVER = server_bonus.c
# CLIENT = client.c
# BONUS_CLIENT = client_bonus.c
# all : 
# 	$(CC) $(CFLAGS) $(SERVER)	-o server																									
# 	$(CC) $(CFLAGS) $(CLIENT) -o client

# bonus : 
# 	$(CC) $(CFLAGS) $(BONUS_SERVER) -o server_bonus
# 	$(CC) $(CFLAGS) $(BONUS_CLIENT) -o client_bonus

# clean : 
# 	rm -rf server client
# 	rm -rf server_bonus client_bonus

# re : clean all



CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_strlen.c ft_calloc.c ft_printf.c ft_free.c client.c  server.c 
OBJ = ${SRC:.c=.o}
BSRC = ft_strlen.c ft_calloc.c ft_printf.c ft_free.c client.c  server.c server_bonus.c client_bonus.c
BOBJ = ${BSRC:.c=.o}
NAME = minitalk.a

all: ${NAME}

${NAME}: ${OBJ}
	ar rcs ${NAME} ${OBJ}

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: 
	cc ${CFLAGS} server.c ${NAME} -o server
	cc ${CFLAGS} client.c ${NAME} -o client

bonus:
	cc ${CFLAGS} server_bonus.c ${NAME} -o server_bonus
	cc ${CFLAGS} client_bonus.c ${NAME} -o client_bonus

clean:
	rm -rf ${OBJ} ${BOBJ} server client server_bonus client_bonus

fclean: clean
	rm -rf ${NAME} ${OBJ} 

re: fclean all