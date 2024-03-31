CC = cc

CFLAGS = -Wall -Wextra -Werror

SERVER = server.c
CLIENT = client.c
all :
	$(CC) $(CFLAGS) $(SERVER) -o server 	
	$(CC) $(CFLAGS) $(CLIENT) -o client

clean : 
	rm -rf server client

re : clean all 