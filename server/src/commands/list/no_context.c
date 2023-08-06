/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** no_context.c file.
*/

#include "core.h"

void handle_list_no_context(parameters_t *p, int i)
{
    FILE *file = fopen(DATA_TEAMS_PATH, "r");

    if (file == NULL) {
        return;
    }
    handle_list_no_context_loop(p, i, file);
    fclose(file);
    valid_response(p, i);
}

void handle_list_no_context_loop(parameters_t *p, int i, FILE *file)
{
    size_t length = 0;
    str_to_args_t *args = NULL;
    char *line = NULL;

    while (getline(&line, &length, file) != -1) {
        args = str_to_args(line);
        if (args == NULL) {
            str_to_args_destroy(args);
            continue;
        }
        my_write(p->client_sockets[i], "TeamUUID/OwnerUUID/Name/Description: ");
        my_write(p->client_sockets[i], line);
        str_to_args_destroy(args);
    }
    my_free(line);
}
