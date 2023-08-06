/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** thread_context.c file.
*/

#include "core.h"

void handle_list_thread_context(parameters_t *p, int i)
{
    FILE *file = fopen(DATA_REPLIES_PATH, "r");

    if (file == NULL) {
        return;
    }
    handle_list_thread_context_loop(p, i, file);
    fclose(file);
    valid_response(p, i);
}

void handle_list_thread_context_loop(parameters_t *p, int i, FILE *file)
{
    size_t length = 0;
    str_to_args_t *args = NULL;
    char *line = NULL;

    while (getline(&line, &length, file) != -1) {
        args = str_to_args(line);
        if (args == NULL || args->nb_args < 2) {
            str_to_args_destroy(args);
            continue;
        }
        if (strcmp(args->args[1], p->thread_uuids[i]) == 0) {
            my_write(p->client_sockets[i], "ReplyUUID/ThreadUUID/OwnerUUID/"
                "Message/Timestamp: ");
            my_write(p->client_sockets[i], line);
        }
        str_to_args_destroy(args);
    }
    my_free(line);
}
