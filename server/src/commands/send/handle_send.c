/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_send.c file.
*/

#include "core.h"

void handle_send(parameters_t *p, int i, char *buffer)
{
    str_to_args_t *args = NULL;
    char *prefix = "/send ";
    char *timestamp = NULL;

    if (strncmp(buffer, prefix, strlen(prefix)) != 0
        || p->is_cmd_executed == true)
        return;
    if ((args = str_to_args(buffer)) == NULL || args->nb_args != 2
        || strlen(args->args[1]) > MAX_BODY_LENGTH)
        return (str_to_args_destroy(args));
    if (is_user_validated(args->args[0]) == false) {
        invalid_user(p, i);
        return (str_to_args_destroy(args));
    }
    timestamp = get_timestamp();
    if (timestamp == NULL)
        return (str_to_args_destroy(args));
    handle_send_add(args, p, i, timestamp);
    handle_send_success(args, p, i);
    destroy_general_handle(NULL, args, NULL, timestamp);
}
