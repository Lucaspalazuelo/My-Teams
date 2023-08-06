/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** invalid_channel.c file.
*/

#include "core.h"

void invalid_channel(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "INVALID_CHANNEL\n");
    p->is_cmd_executed = true;
}
