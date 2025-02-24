NAME		=	maze_solver

OBJ_DIR		=	obj

SRC			=	main.c \
				read_map.c \
				debug.c \
				validate_map.c

OBJ			= $(SRC:%.c=$(OBJ_DIR)/%.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -Iinc -g

# Compilation rule
$(OBJ_DIR)/%.o: %.c inc/maze_solver.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking rule
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o obj/$@

clean:
	$(RM) -rf $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re