NAME 		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz
MINILIBX	= minilibx-linux/libmlx_Linux.a

GNL_DIR		= gnl

SRC_FILES 	= $(GNL_DIR)/get_next_line.c \
				  $(GNL_DIR)/get_next_line_utils.c \
				  main.c \
				  error.c \
				  control.c \
				  control2.c \
				  mlx_init.c \
				  key_hook.c \
				  

OBJ_FILES	= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(MAKE) -C libft --silent
	@$(MAKE) -C minilibx-linux --silent
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_FILES) $(MINILIBX) ./libft/libft.a -o $(NAME)

clean:
	@rm -f $(OBJ_FILES)
	@$(MAKE) -C libft clean --silent
	@$(MAKE) -C ./minilibx-linux clean --silent

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean --silent

re: fclean all

.PHONY: all clean fclean re
