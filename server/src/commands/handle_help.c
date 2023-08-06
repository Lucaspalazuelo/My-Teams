/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_help.c file.
*/

#include "core.h"

void handle_help(parameters_t *p, int i, char *buffer)
{
    FILE *file = NULL;
    char *line = NULL;
    size_t length = 0;

    if (strcmp(buffer, "/help") != 0 || p->is_cmd_executed == true) {
        return;
    }
    file = fopen(ASSETS_HELP_PATH, "r");
    if (file == NULL) {
        return;
    }
    while (getline(&line, &length, file) != -1) {
        my_write(p->client_sockets[i], line);
    }
    destroy_general_handle(line, NULL, file, NULL);
    valid_response(p, i);
}
