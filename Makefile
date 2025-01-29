##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = $(shell find . -name "*.c" ! -path "./tests/*")

SRC_TEST = $(shell find . -name "*.c" ! -name "main.c")

INCLUDE_H := $(shell find include -type d)

INCLUDE = $(INCLUDE_H:%=-I%)

OBJ = $(SRC:%.c=build/%.o)

OBJ_DEBUG = $(SRC:%.c=build-debug/%.o)

OBJ_TEST = $(SRC_TEST:%.c=build-test/%.o)

CFLAGS += -Wextra -Wall -lcrypt $(INCLUDE)

DEBUG_FLAGS = -fsanitize=address -g3 -ggdb -Wextra -Wall -lcrypt $(INCLUDE)

TEST_FLAGS = --coverage -lgcov -lcriterion -lcrypt $(INCLUDE)

NAME = my_sudo

DEBUG_NAME = debug

TESTING_NAME = sudo_test

build/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

build-debug/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(DEBUG_FLAGS) -c $< -o $@

build-test/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(TEST_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

$(DEBUG_NAME): $(OBJ_DEBUG)
	gcc -o $(DEBUG_NAME) $(OBJ_DEBUG) $(DEBUG_FLAGS)

tests_run: $(OBJ_TEST)
	gcc -o $(TESTING_NAME) $(OBJ_TEST) $(TEST_FLAGS)
	./sudo_test

perm: all
	$(shell sudo chown root:root my_sudo)
	$(shell sudo chmod 4755 my_sudo)

perm_debug: debug
	$(shell sudo chown root:root debug)
	$(shell sudo chmod 4755 debug)

clean:
	$(shell find . -type f -name "*.o" -delete)

fclean: clean
	rm -rf build
	rm -rf build-debug
	rm -rf build-test
	rm -f $(NAME)
	rm -f $(DEBUG_NAME)
	rm -f $(TESTING_NAME)

re: fclean all
