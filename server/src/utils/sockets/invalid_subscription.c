/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** invalid_subscription.c file.
*/

#include "core.h"

void invalid_subscription(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "INVALID_SUBSCRIPTION\n");
    p->is_cmd_executed = true;
}
