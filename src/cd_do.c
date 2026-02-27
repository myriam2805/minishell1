/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** cd_do.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <stdio.h>

int my_cd(char **args)
{
    char *path = args[1];

    if (path == NULL) {
        path = getenv("HOME");
    }
    if (chdir(path) == 0) {
        return 0;
    } else {
        perror("cd");
        return 84;
    }
}
