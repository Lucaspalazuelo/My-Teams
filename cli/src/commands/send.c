/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** send
*/

#include "cli.h"

void send_cmd(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);

    if (p->uuid == NULL || p->name == NULL) {
        client_error_unauthorized();
        return;
    }
    client_event_private_message_received(p->uuid, args->args[0]);
    free_tab(p);
}
