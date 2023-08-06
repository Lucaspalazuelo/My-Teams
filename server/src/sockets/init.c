/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** init.c file.
*/

#include "core.h"

void init_socket(parameters_t *p)
{
    create_socket(p);
    load_users();
    init_socket_loop(p);
}
