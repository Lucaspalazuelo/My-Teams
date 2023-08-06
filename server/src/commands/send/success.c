/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** success.c file.
*/

#include "core.h"

void handle_send_success(str_to_args_t *args, parameters_t *p, int i)
{
    char *message = malloc(sizeof(char) * (UUID_LENGTH * 2 + 6
        + strlen("\"MESSAGE_RECEIVED\" ")));

    server_event_private_message_sended(p->uuids[i],args->args[0],
        args->args[1]);
    dprintf(p->client_sockets[i], "OK \"%s\"\n", args->args[1]);
    if (message != NULL) {
        sprintf(message, "\"MESSAGE_RECEIVED\" \"%s\" \"%s\"", p->uuids[i],
            args->args[1]);
        send_event(p, i, message, args->args[0]);
        my_free(message);
    }
    p->is_cmd_executed = true;
}
