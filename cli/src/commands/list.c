/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** list
*/

#include "cli.h"

void list(parameters_t *p)
{
    char **temp = my_str_to_word_array(p->argv[p->count - 1], " \r\n\t");

    for (int i = 0; temp[i] != NULL; i++) {
        if (strncmp(temp[i], "OK", 2) == 0)
            print_list_loop(p);
    }
}

void print_list_loop(parameters_t *p)
{
    char *buffer = tab_to_str(p->argv, p->count);
    char **tab = my_str_to_word_array(buffer, "\n");
    str_to_args_t *args = NULL;
    int size = 0;

    for (int i = 0; tab[i] != NULL; i++)
        size++;
    for (int i = 0; i < size - 1; i++) {
        args = str_to_args(tab[i]);
        context_loop(p, args);
        str_to_args_destroy(args);
    }
    free_tab(p);
}

void context_loop(parameters_t *p, str_to_args_t *args)
{
    time_t message_time = 0;

    if (p->context == TEAM)
        client_print_teams(args->args[0], args->args[1],
        args->args[2]);
    if (p->context == CHANNEL)
        client_team_print_channels(args->args[0], args->args[1],
        args->args[2]);
    if (p->context == THREAD) {
        message_time = str_to_time(args->args[2]);
        client_channel_print_threads(args->args[0], args->args[1],
        message_time, args->args[3], args->args[4]);
        message_time = 0;
    }
    if (p->context == REPLY) {
        message_time = str_to_time(args->args[2]);
        client_thread_print_replies(args->args[0], args->args[1],
        message_time, args->args[3]);
        message_time = 0;
    }
}
