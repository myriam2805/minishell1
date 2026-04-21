/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(const char *a, const char *b, size_t n)
{
    size_t i = 0;

    while (i < n && a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i])
            return (a[i] - b[i]);
        i++;
    }
    if (i == n)
        return (0);
    return (a[i] - b[i]);
}
