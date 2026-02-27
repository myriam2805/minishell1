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

    if ((pid) == -1) {
        perror("fork");
        return 84;
    } else if (pid == 0) {
        if (execve(path, args, env) == -1) {
        perror(path);
        exit(84);
    }
    } else {
        waitpid(pid, &statut, 0);
    }
    return 0;
}
