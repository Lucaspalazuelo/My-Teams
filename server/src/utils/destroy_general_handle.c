/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** destroy_general_handle.c file.
*/

#include "core.h"

void destroy_general_handle(char *str1, str_to_args_t *s, FILE *file,
    char *str2)
{
    my_free(str1);
    my_free(str2);
    str_to_args_destroy(s);
    if (file != NULL) {
        fclose(file);
    }
}
