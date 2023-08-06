/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** success.c file.
*/

#include "core.h"

void handle_subscribe_success(parameters_t *p, int i, char *uuid)
{
    add_file_line(DATA_SUBS_PATH, "\"", false);
    add_file_line(DATA_SUBS_PATH, p->uuids[i], false);
    add_file_line(DATA_SUBS_PATH, "\" \"", false);
    add_file_line(DATA_SUBS_PATH, uuid, false);
    add_file_line(DATA_SUBS_PATH, "\"", true);
    server_event_user_subscribed(uuid, p->uuids[i]);
    dprintf(p->client_sockets[i], "OK \"%s\"\n", uuid);
    p->is_cmd_executed = true;
}
