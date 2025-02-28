NAME = nqueens

SRC =	main.c\
		exit.c

OBJ_DIR = obj

CC = gcc

CFLAGS = -Wall -Wextra -Iinc

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o : %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

clean : $(OBJ)
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

all : $(OBJ_DIR)/$(NAME)

re : fclean all

.PHONY : all re fclean clean 