/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** messages
*/

#include "cli.h"

void messages(parameters_t *p)
{
    char **temp = my_str_to_word_array(p->argv[p->count - 1], " \r\n\t");

    for (int i = 0; temp[i] != NULL; i++) {
        if (strncmp(temp[i], "OK", 2) == 0)
            print_loop_messages(p);
    }
}

void print_loop_messages(parameters_t *p)
{
    char *buffer = tab_to_str(p->argv, p->count);
    char **tab = my_str_to_word_array(buffer, "\n");
    str_to_args_t *args = NULL;
    int size = 0;
    time_t message_time = 0;

    for (int i = 0; tab[i] != NULL; i++)
        size++;
    for (int i = 0; i < size - 1; i++) {
        args = str_to_args(tab[i]);
        message_time = str_to_time(args->args[3]);
        client_private_message_print_messages(args->args[0],
        message_time, args->args[2]);
        message_time = 0;
        str_to_args_destroy(args);
    }
    free_tab(p);
}
