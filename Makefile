##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## A Makefile to compile our library.
##

NAME = mysh

SRC = src/minishell.c \
    src/exit.c \
	src/env_settings.c \
	src/cd_do.c \
	src/exec.c \
main.c

OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -I./include -Wall

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
