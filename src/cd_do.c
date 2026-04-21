/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** cd_do.c
*/

#include <unistd.h>
#include "my.h"
#include <stdio.h>

char *my_getenv(char **env, char *var)
{
    int i = 0;
    int len = 0;

    if (env == NULL || var == NULL)
        return (NULL);
    len = my_strlen(var);
    while (env[i] != NULL) {
        if (my_strncmp(env[i], var, len) == 0 && env[i][len] == '=')
            return (&env[i][len + 1]);
        i++;
    }
    return (NULL);
}

int my_cd(char **args, char ***env)
{
    char *path = args[1];
    char buf[4096];
    char *av[3];

    if (path == NULL)
        path = my_getenv(*env, "HOME");
    if (chdir(path) == -1) {
        perror("cd");
        return 84;
    }
    getcwd(buf, 4096);
    av[0] = "setenv";
    av[1] = "PWD";
    av[2] = buf;
    my_setenv(av, env);
    return 0;
}
