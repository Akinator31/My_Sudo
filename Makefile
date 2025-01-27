##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_printf project
##

SRC = $(shell find . -name "*.c")

INCLUDE_H := $(shell find include -type d)

INCLUDE = $(INCLUDE_H:%=-I%)

OBJ = $(SRC:%.c=build/%.o)

OBJ_TESTING = $(SRC:%.c=build-testing/%.o)

CFLAGS += -Wextra -Wall -lcrypt $(INCLUDE)

TESTING_FLAGS = -g3 -ggdb -Wextra -Wall -lcrypt $(INCLUDE)

NAME = my_sudo

TESTING_NAME = debug

build/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

build-testing/%.o: %.c
	mkdir -p $(dir $@)
	gcc $(TESTING_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

$(TESTING_NAME): $(OBJ_TESTING)
	gcc -o $(TESTING_NAME) $(OBJ_TESTING) $(TESTING_FLAGS)

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
	rm -rf build-testing
	rm -f $(NAME)
	rm -f $(TESTING_NAME)

re: fclean all
