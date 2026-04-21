/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** env_disp.c
*/

#include <unistd.h>
#include <string.h>
#include "my.h"

void env_disp(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
}

char *find_env_var(char *env_name, char **env)
{
    int len = my_strlen(env_name);

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], env_name, len) == 0 && env[i][len] == '=')
            return &env[i][len + 1];
    }
    return NULL;
}

void my_unsetenv(char **av, char ***env)
{
    int i = 0;
    int len = 0;

    if (av[1] == NULL)
        return;
    len = my_strlen(av[1]);
    while ((*env)[i] != NULL) {
        if (my_strncmp((*env)[i], av[1], len) == 0 && (*env)[i][len] == '=')
            break;
        i++;
    }
    if ((*env)[i] == NULL)
        return;
    while ((*env)[i] != NULL) {
        (*env)[i] = (*env)[i + 1];
        i++;
    }
}
