/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** invalid_thread.c file.
*/

#include "core.h"

void invalid_thread(parameters_t *p, int i)
{
    my_write(p->client_sockets[i], "INVALID_THREAD\n");
    p->is_cmd_executed = true;
}
