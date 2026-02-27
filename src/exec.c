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

int my_exec(char *path, char **args, char **env)
{
    pid_t pid = fork();
    int statut;

    if (pid == -1)
        return (84);
    if (pid == 0) {
        execve(path, args, env);
        perror(path);
        exit(84);
    }
    waitpid(pid, &statut, 0);
    return (0);
}
