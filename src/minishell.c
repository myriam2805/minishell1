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

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
        }
        i++;
    }
}

char **get_args(char *buffer)
{
    char **args = malloc(sizeof(char *) * 64);
    char *token = strtok(buffer, " ");
    int i = 0;

    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;
    return (args);
}

int handle_builtins(char **args, char ***env, char *buf)
{
    if (my_strcmp(args[0], "cd") == 0)
        return my_cd(args, env);
    if (my_strcmp(args[0], "pwd") == 0) {
        getcwd(buf, 4096);
        write(1, buf, my_strlen(buf));
        write(1, "\n", 1);
        return (0);
    }
    if (my_strcmp(args[0], "setenv") == 0) {
        my_setenv(args, env);
        return (0);
    }
    if (my_strcmp(args[0], "unsetenv") == 0) {
        my_unsetenv(args, env);
        return (0);
    }
    return my_exec(args[0], args, *env);
}

int manage_flags(char **args, char ***env)
{
    char buf[4096];

    if (my_strcmp(args[0], "exit") == 0)
        exit(0);
    if (my_strcmp(args[0], "env") == 0) {
        env_disp(*env);
        return (0);
    }
    return handle_builtins(args, env, buf);
}

int minishell(char **env)
{
    char *buffer = NULL;
    size_t size = 0;
    char **args = NULL;
    int ret = 0;

    write(1, "$> ", 3);
    while (getline(&buffer, &size, stdin) != -1) {
        clean_line(buffer);
        args = get_args(buffer);
        if (args[0] != NULL)
            ret = manage_flags(args, &env);
        write(1, "$> ", 3);
        free(args);
    }
    free(buffer);
    return ret;
}
