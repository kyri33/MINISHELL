CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = src/*.c
OBJ = *.o
INC = -I./libft/ -I./includes/
LIB = -L./libft -lft

all:
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC) $(INC)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o minishell

clean:
	make clean -C libft/
	rm -f *.o

fclean:
	make fclean -C libft/
	rm -f *.o
	rm -f minishell

re: fclean all
