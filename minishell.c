/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** minishell.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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

void set_et_un_set_env(char **env)
{

}

int exit_command(char *blabla)
{
    char **av;

    if (blabla != NULL && strcmp(blabla, "exit\n") == 0) {
        return 84;
}
    return 0;
}

int minishell(char **env)
{
    char *buffer = NULL;
    size_t size = 0;
    ssize_t read;

    write(1, "myriam$ ", 8);

    while ((read = getline(&buffer, &size,stdin)) != -1) {
        if (exit_command(buffer) == 84) {
            exit(0);
            return 84;
        }
        env_disp(env);
    }
    free(buffer);
    return 0;
}

int main(int ac, char **av, char **env)
{
    minishell(env);
    return 0;
}
