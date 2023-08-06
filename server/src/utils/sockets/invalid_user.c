/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** invalid_user.c file.
*/

#include "core.h"

void invalid_user(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "INVALID_USER\n");
    p->is_cmd_executed = true;
}
