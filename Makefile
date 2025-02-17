NAME = pipex
CFLAGS = -Wall -Werror -Wextra
HFILE = pipex.h
CC = cc

SRCS = main.c utils1.c utils2.c
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf $(OBJ)
	
fclean: clean
	rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean all re
