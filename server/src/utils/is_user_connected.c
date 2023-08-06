/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** is_user_connected.c file.
*/

#include "core.h"

bool is_user_connected(parameters_t *p, char *uuid)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (p->uuids[i] != NULL && strcmp(p->uuids[i], uuid) == 0) {
            return (true);
        }
    }
    return (false);
}
