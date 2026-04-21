/*
** EPITECH PROJECT, 2026
** minishell
** File description:
** main.c
*/
#include "my.h"

int main(int ac, char **av, char **env)
{
    if (ac > 1)
        return 84;
    if (!av)
        return 84;
    return minishell(env);
}
