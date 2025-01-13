NAME = so_long

LIBFT = Libft/libft.a
PRINTF = Libft/Printf/libftprintf.a

MLX42 := MLX42/build/libmlx42.a
MLX42_DIR := MLX42
MLX42_BUILD := MLX42/build
MLX := -L$(MLX42_BUILD) -lmlx42 -ldl -lglfw -pthread -lm


INCLUDE := -Iinclude -IMLX42/include/MLX42
SRC_FILES = so_long.c \
			get_map.c \
			check_map.c \
			check_valid_map.c \
			get_images.c
OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -O2 $(INCLUDE)

all: $(NAME)
	@echo "make    ✅"

$(MLX42):
	cmake -S $(MLX42_DIR) -B $(MLX42_BUILD)
	cmake --build $(MLX42_BUILD) -j4

$(NAME): $(OBJ_FILES) $(PRINTF) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(PRINTF) $(LIBFT) $(MLX) -o $(NAME)

$(LIBFT):
	make -C Libft

$(PRINTF):
	make -C Libft/Printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug:$(OBJ_FILES) $(PRINTF) $(LIBFT) $(MLX42)
	$(CC) -g $(CFLAGS) $(OBJ_FILES) $(PRINTF) $(LIBFT) $(MLX) -o $(NAME)

clean:
	make clean -C Libft
	make clean -C Libft/Printf
	rm -f $(OBJ_FILES)
	rm -rf $(MLX42_BUILD)
	@echo "clean   🌪️"

fclean: clean
	make fclean -C Libft
	make fclean -C Libft/Printf
	rm -f $(NAME)
	@echo "fclean  🔥"

re: fclean all

.SILENT:

.PHONY: all name clean fclean re libmlx