/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** error_handling.c file.
*/

#include "core.h"

void throw_if_errors(int ac, char **av, parameters_t *p)
{
    if (ac == 2) {
        check_port(av[1], p);
    } else {
        my_exit(84, "Invalid command, please use ./myteams_server -help\n", p);
    }
}

void check_port(char *port, parameters_t *p)
{
    char *temp = NULL;
    long converted_port = strtol(port, &temp, 10);

    if (converted_port < 1024 || converted_port > 65535 ) {
        my_exit(84, "Port must be between 1024 and 65535\n", p);
    }
    p->port = converted_port;
}
