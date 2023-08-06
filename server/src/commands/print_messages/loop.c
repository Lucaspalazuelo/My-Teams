/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** loop.c file.
*/

#include "core.h"

void handle_print_messages_loop(parameters_t *p, int i, FILE *file, char *uuid)
{
    size_t length = 0;
    char *line = NULL;
    str_to_args_t *args = NULL;

    while (getline(&line, &length, file) != -1) {
        args = str_to_args(line);
        if (args == NULL || args->nb_args < 2) {
            str_to_args_destroy(args);
            continue;
        }
        if (((strcmp(args->args[0], uuid) == 0
            && strcmp(args->args[1], p->uuids[i]) == 0))
            || ((strcmp(args->args[1], uuid) == 0
            && strcmp(args->args[0], p->uuids[i]) == 0))) {
            dprintf(p->client_sockets[i], "SenderUUID/ReceiverUUID/Message/"
                "Timestamp: %s", line);
        }
        str_to_args_destroy(args);
    }
    my_free(line);
}
