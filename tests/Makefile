##
## EPITECH PROJECT, 2018
## makefiletest
## File description:
## ubit
##

CC := gcc
CPPFLAGS += -I../include/ --coverage -L ../lib/ -lgnl
CFLAGS += -Wall -Wextra -pedantic -std=gnu11
LDFLAGS += -lcriterion --coverage

NAME = tests

SRCS =	../src/rm_space.c	\
	../src/my_strlen.c	\
	../src/my_putstr.c	\
	rm_space_test.c		\
	my_putstr_test.c	\
	my_strlen_test.c	\
	my_strcmp_test.c	\
	get_next_line_test.c	\
	my_str_to_word_array_test.c	\
	../src/my_strcmp.c \
	../src/my_str_to_word_array.c	\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $(NAME)

run: re
	./tests --verbose

clean:
	$(RM) $(OBJS)
	rm -rf ../src/utils/*.gc*
	rm -rf ../src/*.gc*
	rm -rf *.gc*

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean run re
