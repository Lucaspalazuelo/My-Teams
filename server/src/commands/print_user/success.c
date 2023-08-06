/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** success.c file.
*/

#include "core.h"

void handle_print_user_success(parameters_t *p, int i, str_to_args_t *args,
    char *line)
{
    my_write(p->client_sockets[i], "OK Status/UUID/Username: ");
    if (is_user_connected(p, args->args[0]) == true) {
        my_write(p->client_sockets[i], "\"connected\" ");
    } else {
        my_write(p->client_sockets[i], "\"disconnected\" ");
    }
    my_write(p->client_sockets[i], line);
    p->is_cmd_executed = true;
}
