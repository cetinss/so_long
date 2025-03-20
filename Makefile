NAME 			= so_long

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

GNL_DIR = gnl

SRC_FILES 		= $(GNL_DIR)/get_next_line.c \
				  $(GNL_DIR)/get_next_line_utils.c \
				  main.c \
				  error.c \
				  control.c \
				  control2.c \
				  

OBJ_FILES		= $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ_FILES) ./libft/libft.a -o $(NAME)

clean:
	rm -f $(OBJ_FILES)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all clean fclean re
