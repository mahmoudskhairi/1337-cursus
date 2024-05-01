CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

libft = ./libft/libft.a
get_next_line = ./get_next_line/get_next_line.a
NAME = push_swap
NAME2 = checker
PUSH_SWAP = src/push_swap.c
PUSH_SWAPO = $(PUSH_SWAP:.c=.o)
checker_bonus = ./src_bonus/checker_bonus.c ./src_bonus/checker_bonus_utils.c
checker_obj = $(checker_bonus:.c=.o)

all : $(NAME)

$(NAME) : $(PUSH_SWAPO)
	@echo "make..."
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $(PUSH_SWAPO) $(libft) -o $(NAME)
	
%.o:%c
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "make clean..."
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./get_next_line

fclean:
	@echo "make fclean..."
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./get_next_line
	@${RM} $(NAME) $(NAME2) $(PUSH_SWAPO) $(checker_obj)

bonus: $(NAME2)

$(NAME2) : $(checker_obj) ./src_bonus/checker_bonus.h
	@echo "make bonus..."
	@$(MAKE) -C ./libft
	@make -C ./get_next_line
	@$(CC) $(CFLAGS) $(checker_obj) $(libft) $(get_next_line) -o checker

re: fclean all
