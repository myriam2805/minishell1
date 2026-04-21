/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** my_strcmp.c
*/

#include <unistd.h>
#include "my.h"

int exit_command(char *blabla)
{
    if (blabla != NULL && my_strcmp(blabla, "exit\n") == 0) {
        return 84;
    }
    return 0;
}
