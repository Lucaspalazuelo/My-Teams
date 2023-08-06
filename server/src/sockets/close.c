/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** close.c file.
*/

#include "core.h"

void close_socket(parameters_t *p, int i, bool delete_socket)
{
    if (delete_socket == true) {
        my_free(p->uuids[i]);
        close(p->client_sockets[i]);
        my_free(p->team_uuids[i]);
        my_free(p->channel_uuids[i]);
        my_free(p->thread_uuids[i]);
    }
    p->uuids[i] = NULL;
    p->client_sockets[i] = 0;
    p->team_uuids[i] = NULL;
    p->channel_uuids[i] = NULL;
    p->thread_uuids[i] = NULL;
}
