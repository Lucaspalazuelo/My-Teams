/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** buffer.c file.
*/

#include "core.h"

void read_buffer(parameters_t *p, int i)
{
    char buffer[BUFFER_SIZE] = { 0 };

    p->is_cmd_executed = false;
    if (read(p->client_sockets[i], buffer, BUFFER_SIZE) == -1) {
        close_socket(p, i, true);
    } else {
        for (int j = 0; j < BUFFER_SIZE; j++) {
            (buffer[j] == '\n' || buffer[j] == '\r') ? (buffer[j] = '\0') : (0);
        }
        dispatch_commands(p, i, buffer);
    }
}

void dispatch_commands(parameters_t *p, int i, char *buffer)
{
    handle_help(p, i, buffer);
    handle_logout(p, i, buffer);
    if (p->uuids[i] == NULL) {
        handle_login(p, i, buffer);
    }
    if (p->uuids[i] != NULL) {
        handle_subscribe(p, i, buffer);
        handle_info(p, i, buffer);
        handle_list(p, i, buffer);
        handle_create(p, i, buffer);
        handle_send(p, i, buffer);
        handle_print_users(p, i, buffer);
        handle_print_user(p, i, buffer);
        handle_use(p, i, buffer);
        handle_print_messages(p, i, buffer);
    }
    if (p->is_cmd_executed == false) {
        my_write(p->client_sockets[i], "INVALID_COMMAND\n");
    }
}
