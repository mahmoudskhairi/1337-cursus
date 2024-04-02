CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server.c
BONUS_SERVER = server_bonus.c
CLIENT = client.c
BONUS_CLIENT = client_bonus.c

all :
	$(CC) $(CFLAGS) $(SERVER) -o server 	
	$(CC) $(CFLAGS) $(CLIENT) -o client

bonus : 
	$(CC) $(CFLAGS) $(BONUS_SERVER) -o server_bonus
	$(CC) $(CFLAGS) $(BONUS_CLIENT) -o client_bonus
clean : 
	rm -rf server client
	rm -rf server_bonus client_bonus
	

re : clean all bonus