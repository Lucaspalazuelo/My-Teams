/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_logout.c file.
*/

#include "core.h"

void handle_logout(parameters_t *p, int i, char *buffer)
{
    if (strcmp(buffer, "/logout") != 0 || p->is_cmd_executed == true) {
        return;
    }
    if (p->uuids[i] != NULL) {
        server_event_user_logged_out(p->uuids[i]);
    }
    valid_response(p, i);
    close_socket(p, i, true);
}
