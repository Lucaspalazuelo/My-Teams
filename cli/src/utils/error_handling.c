/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** error_handling.c file.
*/

#include "cli.h"

void error_handling_throw_if_errors(int ac, char **av, parameters_t *p)
{
    if (ac == 3) {
        error_handling_check_port(av[2], p);
        error_handling_check_ip(av[1], p);
    } else {
        error_handling_unknown_command(p);
    }
}

void error_handling_check_port(char *port, parameters_t *p)
{
    char *temp = NULL;
    long int int_port;

    int_port = strtol(port, &temp, 10);
    if (int_port < 1024 || int_port > 65535 ) {
        my_exit(84, "Port isn't between 1024 and 65535\n", p);
    }
    p->port = (int)int_port;
}

void error_handling_check_ip(char *ip, parameters_t *p)
{
    if (ip == NULL)
        my_exit(84, "Invalid ip\n", p);
    p->ip = strdup(ip);
}

void error_handling_unknown_command(parameters_t *p)
{
    my_exit(84, "Unknown command, please use -help to get the list of"
        " commands\n", p);
}
