/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** logout
*/

#include "cli.h"

void logout(parameters_t *p)
{
    if (p->uuid == NULL || p->name == NULL)
        return;
    client_event_logged_out(p->uuid, p->name);
    close(p->current_socket);
    free_tab(p);
    my_exit(0, NULL, p);
}
