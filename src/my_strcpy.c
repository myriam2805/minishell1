/*
** EPITECH PROJECT, 2026
** minishell1
** File description:
** my_strcpy.c
*/

#include "my.h"

char *my_strcpy(char *dest, char *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}
