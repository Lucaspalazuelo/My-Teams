/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** parameters.c file.
*/

#include "cli.h"

void parameters_destroy(parameters_t *p)
{
    my_free(p);
}
