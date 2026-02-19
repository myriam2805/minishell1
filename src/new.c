/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** new.c
*/

#include <unistd.h>

int my_strlen(char *str)
{
     int len = 0;
    while (str[len] != '\0') 
        len = len + 1;
    return len;
}

void env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        write(1, env[i], my_strlen(env[i]));
    }
}
