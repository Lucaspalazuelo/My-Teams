/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** info
*/

#include "cli.h"

void info(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);
    time_t message_time;
    int status = 0;

    if (p->context == TEAM) {
        if (strcmp(args->args[0], "connected") == 0)
            status = 1;
        client_print_user(args->args[0], args->args[1], status);
    }
    if (p->context == CHANNEL)
        client_print_team(args->args[0], args->args[1], args->args[2]);
    if (p->context == THREAD)
        client_print_channel(args->args[0], args->args[1], args->args[2]);
    if (p->context == REPLY) {
        message_time = str_to_time(args->args[2]);
        client_print_thread(args->args[0], args->args[1], message_time,
        args->args[3], args->args[4]);
    }
    free_tab(p);
}
