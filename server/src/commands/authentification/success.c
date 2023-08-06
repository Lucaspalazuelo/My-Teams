/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** success.c file.
*/

#include "core.h"

void handle_login_success(parameters_t *p, int i, char *uuid, char *name)
{
    dprintf(p->client_sockets[i], "OK \"%s\" \"%s\"\n", name, uuid);
    p->uuids[i] = uuid;
    p->is_cmd_executed = true;
}
