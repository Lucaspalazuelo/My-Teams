/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** socket.c file.
*/

#include "cli.h"

void socket_init(parameters_t *p)
{
    socket_create(p);
    socket_loop(p);
}

void socket_create(parameters_t *p)
{
    struct sockaddr_in current_socket_address;

    p->current_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (p->current_socket == -1) {
        my_exit(84, "Socket (socket) failed\n", p);
    }
    current_socket_address.sin_family = AF_INET;
    current_socket_address.sin_port = htons(p->port);
    if (inet_pton(AF_INET, p->ip, &current_socket_address.sin_addr) <= 0) {
        my_exit(84, "Socket (inet_pton) failed\n", p);
    }
    if (connect(p->current_socket, (struct sockaddr *)&current_socket_address,
        sizeof(current_socket_address)) < 0) {
        my_exit(84, "Socket (connect) failed\n", p);
    }
}
