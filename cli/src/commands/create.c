/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** create
*/

#include "cli.h"

void create(parameters_t *p)
{
    str_to_args_t *args = str_to_args(p->argv[0]);
    time_t message_time;

    if (p->context == TEAM)
        client_print_team_created(args->args[0], args->args[1], args->args[2]);
    if (p->context == CHANNEL)
        client_print_channel_created(args->args[0],
        args->args[1], args->args[2]);
    if (p->context == THREAD) {
        message_time = str_to_time(args->args[2]);
        client_print_thread_created(args->args[0], args->args[1], message_time,
        args->args[3], args->args[4]);
    }
    if (p->context == REPLY) {
        message_time = str_to_time(args->args[2]);
        client_print_reply_created(args->args[0], args->args[1], message_time,
        args->args[3]);
    }
    free_tab(p);
}
