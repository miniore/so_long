NAME = so_long

LIBFT = Libft/libft.a
PRINTF = Libft/Printf/libftprintf.a
LIBMLX = MLX42


HEADERS	:= -I ./include -I $(LIBMLX)/include
SRC_FILES = so_long.c \
			get_map.c \
			check_map.c
OBJ_FILES = $(SRC_FILES:.c=.o)
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast

all: libmlx $(NAME)
	@echo "make    ✅"

ibmlx:
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build && cmake --build $(LIBMLX)/build -j4

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
	rm -rf $(LIBMLX)/build
	@echo "clean   🌪️"

fclean: clean
	make fclean -C Libft
	make fclean -C Libft/Printf
	rm -f $(NAME)
	@echo "fclean  🔥"

re: fclean all

.SILENT:

.PHONY: all name clean fclean re libmlx