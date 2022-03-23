##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## create a makefile
##

NAME = liblist.a

SOURCE := list_create.c\
		list_add.c\
		swap.c\
		free.c\
		get.c\
		rm.c\
		cast_from_list.c\
		str_to_word_list.c
SOURCE := $(addprefix src/,$(SOURCE))

TEST_SOURCE = list_create.c\
		list_add.c\
		tests/lib_list_test.c\
		swap.c\
		free.c\
		get.c\
		rm.c\
		str_to_word_list.c

OBJ = $(SOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Wpedantic -I../include/

LIB = -L . -lmy

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

debug: CFLAGS += -g3
debug: fclean $(NAME)

tests_run: fclean
	gcc -o unit_tests $(TEST_SOURCE) --coverage -lcriterion $(CFLAGS)
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
