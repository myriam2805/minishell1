/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** setenv.c
*/

#include "my.h"
#include <stdlib.h>
#include <string.h>

char *make_entry(char *name, char *value)
{
    char *entry = malloc(my_strlen(name) + my_strlen(value) + 2);

    if (entry == NULL)
        return NULL;
    my_strcpy(entry, name);
    my_strcat(entry, "=");
    my_strcat(entry, value);
    return entry;
}

char **add_to_env(char **env, char *new_entry, int i)
{
    char **new_env = malloc(sizeof(char *) * (i + 2));

    if (new_env == NULL)
        return env;
    for (int j = 0; j < i; j++)
        new_env[j] = env[j];
    new_env[i] = new_entry;
    new_env[i + 1] = NULL;
    return new_env;
}

void my_setenv(char **av, char ***env)
{
    int i = 0;
    int len = 0;
    char *new_entry = NULL;

    if (av[1] == NULL || av[2] == NULL)
        return;
    len = my_strlen(av[1]);
    new_entry = make_entry(av[1], av[2]);
    while ((*env)[i] != NULL) {
        if (my_strncmp((*env)[i], av[1], len) == 0 && (*env)[i][len] == '=') {
            (*env)[i] = new_entry;
            return;
        }
        i++;
    }
    *env = add_to_env(*env, new_entry, i);
}
