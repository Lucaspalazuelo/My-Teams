/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** loop.c file.
*/

#include "core.h"

void handle_print_users_loop(parameters_t *p, int i, FILE *file)
{
    size_t length = 0;
    str_to_args_t *args = NULL;
    char *line = NULL;

    while (getline(&line, &length, file) != -1) {
        args = str_to_args(line);
        if (args == NULL || args->nb_args == 0) {
            str_to_args_destroy(args);
            continue;
        }
        my_write(p->client_sockets[i], "Status/UUID/Username: ");
        if (is_user_connected(p, args->args[0]) == true) {
            my_write(p->client_sockets[i], "\"connected\" ");
        } else {
            my_write(p->client_sockets[i], "\"disconnected\" ");
        }
        my_write(p->client_sockets[i], line);
        str_to_args_destroy(args);
    }
    my_free(line);
}
