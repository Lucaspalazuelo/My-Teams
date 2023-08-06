/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** already_subscribed.c file.
*/

#include "core.h"

void already_subscribed(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "ALREADY_SUBSCRIBED\n");
    p->is_cmd_executed = true;
}
