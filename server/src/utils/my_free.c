/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** my_free.c file.
*/

#include "core.h"

void my_free(void *pointer)
{
    if (pointer != NULL) {
        free(pointer);
    }
}
