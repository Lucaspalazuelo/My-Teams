/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** valid_response.c file.
*/

#include "core.h"

void valid_response(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "OK\n");
    p->is_cmd_executed = true;
}
