/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** main.c file.
*/

#include "core.h"

int main(int ac, char **av)
{
    parameters_t *p = malloc(sizeof(parameters_t));

    if (p == NULL) {
        my_exit(84, "Malloc (parameters) failed\n", p);
    }
    print_help(ac, av, p);
    throw_if_errors(ac, av, p);
    init_socket(p);
    my_exit(0, NULL, p);
}
