# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khamusek <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/11 13:11:21 by khamusek          #+#    #+#              #
#    Updated: 2016/08/17 15:29:22 by khamusek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
SRC = src/ft_cd.c src/ft_del_args.c src/ft_echo.c src/ft_env.c src/ft_error.c \
	  src/ft_execute.c src/ft_exit.c src/ft_fill_args.c src/ft_get_user.c \
	  src/ft_parse_command.c src/ft_pwd.c src/ft_rem_spaces.c src/ft_setenv.c \
	  src/ft_unsetenv.c src/minishell.c src/ft_get_env.c src/ft_get_env_name.c \
	  src/ft_get_env_val.c src/ft_strjoin_path.c src/ft_handle_vars.c
OBJ = ft_cd.o ft_del_args.o ft_echo.o ft_env.o ft_error.o ft_execute.o \
	  ft_exit.o ft_fill_args.o ft_get_user.o ft_parse_command.o ft_pwd.o \
	  ft_rem_spaces.o ft_setenv.o ft_unsetenv.o minishell.o ft_get_env.o \
	  ft_get_env_name.o ft_get_env_val.o ft_strjoin_path.o ft_handle_vars.o
INC = -I./libft/ -I./includes/
LIB = -L./libft -lft
TARG = 21sh

all:
	make -C libft/
	$(CC) $(CFLAGS) -c $(SRC) $(INC)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(TARG)

rem_obj:
	rm -f $(OBJ)

clean: rem_obj
	make clean -C libft/

fclean: rem_obj
	make fclean -C libft/
	rm -f $(TARG)

re: fclean all
