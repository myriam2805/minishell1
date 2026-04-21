/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** exec.c
*/

#include "my.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

char *build_path(char *token, char *cmd)
{
    char *full = malloc(my_strlen(token) + my_strlen(cmd) + 2);

    if (full == NULL)
        return NULL;
    my_strcpy(full, token);
    my_strcat(full, "/");
    my_strcat(full, cmd);
    return full;
}

char *search_in_path(char *path, char *cmd)
{
    char *start = path;
    char *end;
    char *full;

    while (*start) {
        end = start;
        while (*end && *end != ':')
            end++;
        *end = '\0';
        full = build_path(start, cmd);
        if (full && access(full, X_OK) == 0)
            return full;
        free(full);
        start = end + 1;
    }
    return NULL;
}

char *find_path(char *cmd, char **env)
{
    char *path;
    char *full;

    if (cmd && access(cmd, X_OK) == 0)
        return cmd;
    path = find_env_var("PATH", env);
    if (!path)
        return NULL;
    path = my_strdup(path);
    full = search_in_path(path, cmd);
    free(path);
    return full;
}

int my_exec(char *cmd, char **args, char **env)
{
    char *path = find_path(cmd, env);
    pid_t pid;
    int statut;

    if (path == NULL) {
        write(2, "command not found\n", 18);
        return 127;
    }
    pid = fork();
    if (pid == -1)
        return (84);
    if (pid == 0) {
        execve(path, args, env);
        perror(path);
        exit(84);
    }
    waitpid(pid, &statut, 0);
    return (statut >> 8) & 0xff;
}
