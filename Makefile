NAME = so_long

LIBFT = Libft/libft.a
PRINTF = Libft/Printf/libftprintf.a

SRC_FILES = so_long.c
OBJ_FILES = $(SRC_FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3

all:$(NAME)
	@echo "make    ✅"

$(NAME): $(OBJ_FILES) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft

$(PRINTF):
	make -C Libft/Printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C Libft
	make clean -C Libft/Printf
	rm -f $(OBJ_FILES)
	@echo "clean   🌪️"

fclean: clean
	make fclean -C Libft
	make fclean -C Libft/Printf
	rm -f $(NAME)
	@echo "fclean  🔥"

re: fclean all

.SILENT:

.PHONY: all name clean fclean re