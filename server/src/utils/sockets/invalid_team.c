/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** invalid_team.c file.
*/

#include "core.h"

void invalid_team(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "INVALID_TEAM\n");
    p->is_cmd_executed = true;
}
