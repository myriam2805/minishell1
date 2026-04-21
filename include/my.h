/*
** EPITECH PROJECT, 2025
** my header file
** File description:
** A header to connect all functions together.
*/
#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
int my_strlen(char *str);
void env_disp(char **env);
int my_strcmp(const char *a, const char *b);
int exit_command(char *blabla);
int minishell(char **env);
int my_cd(char **args, char ***env);
char *my_getenv(char **env, char *var);
void my_setenv(char **av, char ***env);
int my_exec(char *cmd, char **args, char **env);
void my_unsetenv(char **av, char ***env);
int my_strncmp(char const *s1, char const *s2, size_t n);
void clean_line(char *str);
char **get_args(char *buffer);
int manage_flags(char **args, char ***env);
char *my_strdup(char *src);
int my_strlen(char *src);
char *find_env_var(char *env_name, char **env);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, const char *src);
char *my_strncpy(char *dst, const char *src, size_t n);
char *search_in_path(char *path, char *cmd);

#endif
