/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** close_socket.c file.
*/

#include "cli.h"

void close_socket(parameters_t *p, bool delete_socket)
{
    if (delete_socket == true) {
        close(p->temporary_socket);
    }
    p->temporary_socket = 0;
}
