/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_login.c file.
*/

#include "core.h"

void handle_login(parameters_t *p, int i, char *buffer)
{
    char *prefix = "/login ";
    str_to_args_t *args = NULL;
    char *line = NULL;
    char *uuid = NULL;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0
        || p->is_cmd_executed == true)
        return;
    args = str_to_args(buffer);
    if (args == NULL || args->nb_args != 1
        || strlen(args->args[0]) > MAX_NAME_LENGTH)
        return (str_to_args_destroy(args));
    line = search_file_line(DATA_USERS_PATH, args->args[0], UUID_LENGTH + 4,
        (int)strlen(args->args[0]));
    uuid = register_or_login(args, line);
    if (uuid == NULL)
        return (destroy_general_handle(line, args, NULL, NULL));
    handle_login_success(p, i, uuid, args->args[0]);
    destroy_general_handle(line, args, NULL, NULL);
}
