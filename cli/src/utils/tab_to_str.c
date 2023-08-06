/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** tab_to_char
*/

#include "cli.h"

char *tab_to_str(char **tab, int tab_size)
{
    char *result = NULL;
    int size = 0;
    int offset = 0;

    for (int i = 0; i < tab_size; i++)
        size += strlen(tab[i]);
    result = malloc(size + 1);
    for (int i = 0; i < tab_size; i++) {
        strcpy(result + offset, tab[i]);
        offset += strlen(tab[i]);
    }
    return result;
}
