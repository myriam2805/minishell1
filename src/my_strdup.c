/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** my_strdup.c
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char *src)
{
    char *dest = NULL;
    int len = 0;

    if (!src)
        return NULL;
    len = my_strlen(src);
    dest = malloc(len + 1);
    if (dest == NULL)
        return NULL;
    for (int n = 0; n < len; n++)
        dest[n] = src[n];
    dest[len] = '\0';
    return dest;
}
