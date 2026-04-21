/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(const char *a, const char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    return (a[i] - b[i]);
}
