##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile
##

NAME	=	42sh

SRC	=	./src/main.c			\
		./src/main_tools.c		\
		./src/my_cd.c			\
		./src/make_path.c		\
		./src/my_exit.c			\
		./src/my_env.c			\
		./src/my_setenv_new.c		\
		./src/env_find.c		\
		./src/my_setenv.c		\
		./src/my_unsetenv.c		\
		./src/exec_bin.c		\
		./src/exe_path.c		\
		./src/path.c			\
		./src/how_many_are_we.c		\
		./src/my_get_nbr.c		\
		./src/my_strcmp.c		\
		./src/my_strlen.c		\
		./src/my_str_to_word_array.c	\
		./src/how_many_char_star.c	\
		./src/my_putstr.c		\
		./src/my_strcpy.c		\
		./src/my_strncmp.c		\
		./src/rm_space.c		\
		./src/my_strtok.c		\
		./src/parsing.c			\
		./src/define_type.c		\
		./src/my_cutstr.c		\
		./src/exist_opt.c		\
		./src/testing_loop_shell1.c	\
		./src/aliases.c			\
		./src/aliases_tools.c		\
		./src/history.c			\
		./src/gnl.c			\
		./src/read_execution.c		\
		./src/my_concat.c		\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= -Iinclude

MAKE := make

CC	=	gcc -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

fclean : clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)

re :	fclean all

.PHONY:	all fclean clean re test_run
