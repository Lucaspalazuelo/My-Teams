/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** socket_loop.c file.
*/

#include "cli.h"

_Noreturn void socket_loop(parameters_t *p)
{
    while (1) {
        FD_ZERO(&p->sockets);
        FD_SET(p->current_socket, &p->sockets);
        FD_SET(STDIN_FILENO, &p->sockets);
        p->temporary_socket = p->current_socket;
        socket_loop_select(p);
        socket_loop_handle_connections(p);
    }
}

void socket_loop_select(parameters_t *p)
{
    if (select(p->temporary_socket + 1, &p->sockets, NULL, NULL, NULL) == -1) {
        my_exit(84, "Socket (select) failed\n", p);
    }
}

void socket_loop_handle_connections(parameters_t *p)
{
    if (FD_ISSET(p->temporary_socket, &p->sockets) > 0) {
        connections_loop(p);
    }
    if (FD_ISSET(STDIN_FILENO, &p->sockets) > 0) {
        input_loop(p);
    }
}
