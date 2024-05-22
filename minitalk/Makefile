CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
UTILS = ./utils/utils.a

SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SV_MANDATORY = mandatory/server.c
SV_OBJ = $(SV_MANDATORY:.c=.o)

CL_MANDATORY = mandatory/client.c
CL_OBJ = $(CL_MANDATORY:.c=.o)

SV_BONUS_SRC = bonus/server_bonus.c
SV_BONUS_OBJ = $(SV_BONUS_SRC:.c=.o)

CL_BONUS_SRC = bonus/client_bonus.c
CL_BONUS_OBJ = $(CL_BONUS_SRC:.c=.o)

all: $(SERVER) $(CLIENT)
	@echo "                           █████                                              █████"
	@echo "                          ░░███                                              ░░███" 
	@echo " █████████████    ██████   ░███████   █████████████    ██████  █████ ████  ███████"
	@echo "░░███░░███░░███  ░░░░░███  ░███░░███ ░░███░░███░░███  ███░░███░░███ ░███  ███░░███" 
	@echo " ░███ ░███ ░███   ███████  ░███ ░███  ░███ ░███ ░███ ░███ ░███ ░███ ░███ ░███ ░███" 
	@echo " ░███ ░███ ░███  ███░░███  ░███ ░███  ░███ ░███ ░███ ░███ ░███ ░███ ░███ ░███ ░███" 
	@echo " █████░███ █████░░████████ ████ █████ █████░███ █████░░██████  ░░████████░░████████"
	@echo "░░░░░ ░░░ ░░░░░  ░░░░░░░░ ░░░░ ░░░░░ ░░░░░ ░░░ ░░░░░  ░░░░░░    ░░░░░░░░  ░░░░░░░░" 
%.o:%.c ./includes/minitalk.h ./includes_bonus/minitalk_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(UTILS):
	@$(MAKE) -C ./utils
$(SERVER): $(SV_OBJ) $(UTILS)
	@$(CC) $(CFLAGS) $(SV_OBJ) $(UTILS) -o server
$(CLIENT): $(CL_OBJ) $(UTILS)
	@$(CC) $(CFLAGS) $(CL_OBJ) $(UTILS) -o client
	
$(SERVER_BONUS): $(SV_BONUS_OBJ) $(UTILS)
	@$(CC) $(CFLAGS) $(SV_BONUS_OBJ) $(UTILS) -o server_bonus
$(CLIENT_BONUS): $(CL_BONUS_OBJ) $(UTILS)
	@$(CC) $(CFLAGS) $(CL_BONUS_OBJ) $(UTILS) -o client_bonus

clean:
	@$(MAKE) clean -C ./utils
	@$(RM) $(SV_OBJ) $(CL_OBJ)
	@$(RM) $(SV_BONUS_OBJS) $(CL_BONUS_OBJ) 
fclean: clean
	@$(MAKE) fclean -C ./utils
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
re: fclean all

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)