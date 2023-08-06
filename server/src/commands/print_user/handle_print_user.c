/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_print_user.c file.
*/

#include "core.h"

void handle_print_user(parameters_t *p, int i, char *buffer)
{
    char *prefix = "/user ";
    str_to_args_t *args = NULL;
    char *line = NULL;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0
        || p->is_cmd_executed == true)
        return;
    args = str_to_args(buffer);
    if (args == NULL || args->nb_args != 1)
        return (str_to_args_destroy(args));
    line = search_file_line(DATA_USERS_PATH, args->args[0], 1, UUID_LENGTH);
    str_to_args_destroy(args);
    if (line == NULL)
        return (invalid_user(p, i));
    args = str_to_args(line);
    if (args == NULL || args->nb_args == 0)
        return (destroy_general_handle(line, args, NULL, NULL));
    handle_print_user_success(p, i, args, line);
    destroy_general_handle(line, args, NULL, NULL);
}
