##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## A Makefile to compile our library.
##

NAME = mysh

SRC = src/minishell.c \
    src/exit.c \
	src/unsetenv.c \
	src/cd_do.c \
	src/exec.c \
	src/my_strlen.c \
	src/my_strdup.c \
	src/setenv.c \
	src/my_strncmp.c \
	src/my_strcmp.c \
	src/my_strcat.c \
	src/my_strcpy.c \
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
