/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** send_event.c file.
*/

#include "core.h"

void send_event(parameters_t *p, int i, char *message, char *uuid)
{
    for (int j = 0; j < MAX_CLIENTS; j++) {
        if (p->uuids[j] != NULL && strcmp(p->uuids[j], uuid) == 0
            && strcmp(p->uuids[i], p->uuids[j]) != 0) {
            my_write(p->client_sockets[j], message);
        }
    }
}
