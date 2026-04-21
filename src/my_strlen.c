/*
** EPITECH PROJECT, 2026
** my_strlen
** File description:
** A function that prints the lenght of a string.
*/
#include "my.h"

int my_strlen(char *src)
{
    int lenght = 0;

    for (int i = 0; src[i] != '\0'; i++)
        lenght = lenght + 1;
    return lenght;
}
