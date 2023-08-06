/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** my_exit.c file.
*/

#include "cli.h"

void my_exit(int code, char *message, parameters_t *p)
{
    if (message != NULL) {
        printf("%s", message);
    }
    parameters_destroy(p);
    exit(code);
}
