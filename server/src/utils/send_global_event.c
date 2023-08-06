/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** send_global_event.c file.
*/

#include "core.h"

void send_global_event(parameters_t *p, int i, char *message, char *uuid)
{
    FILE *file = fopen(DATA_SUBS_PATH, "r");
    char *line = NULL;
    size_t length = 0;
    str_to_args_t *args = NULL;

    if (file == NULL) {
        return;
    }
    while (getline(&line, &length, file) != -1) {
        args = str_to_args(line);
        if (args == NULL || args->nb_args < 2
            || strcmp(args->args[1], uuid) != 0) {
            str_to_args_destroy(args);
            continue;
        }
        send_event(p, i, message, args->args[0]);
        str_to_args_destroy(args);
    }
    fclose(file);
    my_free(line);
}
