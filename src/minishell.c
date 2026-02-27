/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** minishell.c
*/

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

void clean_line(char *str)
{
    int i = 0;
    while (str[i]) {
        if (str[i] == '\n') str[i] = '\0';
        i++;
    }
}

char **get_args(char *buffer)
{
    char **args = malloc(sizeof(char *) * 64);
    char *token = strtok(buffer, " ");
    int i = 0;

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return (args);
}

int manage_flags(char **av)
{
    char *buffer = NULL;
    char **env = NULL;
    char **args = get_args(buffer);

    if (my_strcmp(args[0], "exit") == 0)
            exit(0);
    else if (my_strcmp(args[0], "env") == 0)
            env_disp(env);
    else if (my_strcmp(args[0], "cd") == 0)
            my_cd(args);
    else if (my_strcmp(args[0], "unsetenv") == 0) {
            my_unsetenv(args, &env);
        }
    else
        my_exec(args[0], args, env);
    write(1, "myriam$ ", 8);
    free(args);
    return 0;
}

int minishell(char **env)
{
    char *buffer = NULL;
    size_t size = 0;

    write(1, "myriam$ ", 8);
    while (getline(&buffer, &size, stdin) != -1) {
        clean_line(buffer);
        char **args = get_args(buffer);

        if (args[0] == NULL) {
            write(1, "myriam$ ", 8);
            continue;
        }
        manage_flags(env);
    }
    free(buffer);
    return 0;
}
