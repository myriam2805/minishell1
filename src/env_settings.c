/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** env_disp.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n <= 0)
        return (0);
    while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len = len + 1;
    return len;
}

void env_disp(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
}

void my_unsetenv(char **av, char ***env)
{
    int i = 0;
    int len = 0;

    if (av[1] == NULL)
        return;
    len = my_strlen(av[1]);
    while ((*env)[i] != NULL) {
        if (my_strncmp((*env)[i], av[1], len) == 0 && (*env)[i][len] == '=') {
            while ((*env)[i] != NULL) {
                (*env)[i] = (*env)[i + 1];
                i++;
            }
            return;
        }
        i++;
    }
}
