/*
** EPITECH PROJECT, 2022
** my_str_to_word_array.c
** File description:
** my_str_to_word
*/

#include "cli.h"

int check_separators(char c, char *separator)
{
    int i = 0;

    if (!separator)
        return (1);
    while (separator[i] != '\0') {
        if (c == separator[i])
            return (0);
        i++;
    }
    return (1);
}

static char *get_arg(char *str, int *j, char *separators)
{
    char *temp;
    int i = 0;

    while (check_separators(str[*j], separators) == 0)
        *j += 1;
    while (check_separators(str[*j + i], separators) == 1
    && str[*j + i] != '\0')
        i += 1;
    if ((temp = malloc(i + 1)) == NULL)
        return (NULL);
    temp[i] = '\0';
    i = 0;
    while (check_separators(str[*j], separators) == 1 && str[*j] != '\0') {
        temp[i] = str[*j];
        i += 1;
        *j += 1;
    }
    return (temp);
}

int get_nb_argv(char *str, char *separators)
{
    int i = 0;
    int y = 0;

    while (check_separators(str[y], separators) == 0 && str[y] != '\0')
        y += 1;
    while (str[y] != '\0') {
        if (check_separators(str[y], separators) == 1 && str[y] != '\0' &&
        (check_separators(str[y + 1], separators) == 0 || str[y + 1] == '\0'))
            i += 1;
        y += 1;
    }
    return (i);
}

char **my_str_to_word_array(char *str, char *separators)
{
    int i = get_nb_argv(str, separators);
    char **argv;
    int j = 0;
    int y = 0;

    if (!separators) {
        argv = &str;
        return (argv);
    }
    if ((argv = malloc(sizeof(char *) * (i + 1))) == NULL)
        return (NULL);
    while (y < i) {
        argv[y] = get_arg(str, &j, separators);
        y += 1;
    }
    argv[y] = NULL;
    return (argv);
}
