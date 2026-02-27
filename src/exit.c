/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** my_strcmp.c
*/

#include <unistd.h>
#include "my.h"

int my_strcmp(const char *a, const char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (a[i] - b[i]);
}

int exit_command(char *blabla)
{
    if (blabla != NULL && my_strcmp(blabla, "exit\n") == 0) {
        return 84;
    }
    return 0;
}
