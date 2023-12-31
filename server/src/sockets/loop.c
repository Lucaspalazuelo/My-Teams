/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** loop.c file.
*/

#include "core.h"

_Noreturn void init_socket_loop(parameters_t *p)
{
    init_parameters(p);
    printf("Server started on port %d\n", p->port);
    while (1) {
        FD_ZERO(&p->sockets);
        FD_SET(p->current_socket, &p->sockets);
        p->temp_socket = p->current_socket;
        add_socket_connections(p);
        select_socket_connections(p);
        accept_socket_connections(p);
        handle_socket_connections(p);
    }
}

void add_socket_connections(parameters_t *p)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (p->client_sockets[i] == 0) {
            continue;
        }
        FD_SET(p->client_sockets[i], &p->sockets);
        if (p->client_sockets[i] > p->temp_socket) {
            p->temp_socket = p->client_sockets[i];
        }
    }
}

void select_socket_connections(parameters_t *p)
{
    if (select(p->temp_socket + 1, &p->sockets, NULL, NULL, NULL) == -1) {
        my_exit(84, "Socket (select) failed\n", p);
    }
}

void accept_socket_connections(parameters_t *p)
{
    struct sockaddr_in client_socket_address;
    socklen_t client_socket_address_size;
    int new_client_socket;

    if (FD_ISSET(p->current_socket, &p->sockets) <= 0)
        return;
    client_socket_address_size = sizeof(client_socket_address);
    new_client_socket = accept(p->current_socket,
        (struct sockaddr *)&client_socket_address,
        &client_socket_address_size);
    if (new_client_socket == -1)
        my_exit(84, "Socket (accept) failed\n", p);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (p->client_sockets[i] == 0) {
            p->client_sockets[i] = new_client_socket;
            my_write(p->client_sockets[i], "OK\n");
            break;
        }
    }
}

void handle_socket_connections(parameters_t *p)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (FD_ISSET(p->client_sockets[i], &p->sockets) > 0) {
            read_buffer(p, i);
        }
    }
}
