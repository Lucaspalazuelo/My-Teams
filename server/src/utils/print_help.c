/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** print_help.c file.
*/

#include "core.h"

void print_help(int ac, char **av, parameters_t *p)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        my_exit(0, "USAGE: ./myteams_server port\n\n\t"
            "port is the port number on which the server socket listens\n", p);
    }
}
