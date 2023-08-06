/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** add.c file.
*/

#include "core.h"

void handle_send_add(str_to_args_t *args, parameters_t *p, int i,
    char *timestamp)
{
    add_file_line(DATA_MESSAGES_PATH, "\"", false);
    add_file_line(DATA_MESSAGES_PATH, p->uuids[i], false);
    add_file_line(DATA_MESSAGES_PATH, "\" \"", false);
    add_file_line(DATA_MESSAGES_PATH, args->args[0], false);
    add_file_line(DATA_MESSAGES_PATH, "\" \"", false);
    add_file_line(DATA_MESSAGES_PATH, args->args[1], false);
    add_file_line(DATA_MESSAGES_PATH, "\" \"", false);
    add_file_line(DATA_MESSAGES_PATH, timestamp, false);
    add_file_line(DATA_MESSAGES_PATH, "\"", true);
}
