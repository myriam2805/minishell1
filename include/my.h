/*
** EPITECH PROJECT, 2025
** my header file
** File description:
** A header to connect all functions together.
*/
#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
void minishell(void);
int my_strcmp(const char *a, const char *b);
int exit_command(char **av);
#endif