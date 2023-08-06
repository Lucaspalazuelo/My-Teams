/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_subscribe.c file.
*/

#include "core.h"

void handle_subscribe(parameters_t *p, int i, char *buffer)
{
    str_to_args_t *args = NULL;
    char *prefix = "/subscribe ";

    if (strncmp(buffer, prefix, strlen(prefix)) != 0 || p->is_cmd_executed) {
        return;
    }
    args = str_to_args(buffer);
    if (args == NULL || args->nb_args != 1) {
        return (str_to_args_destroy(args));
    }
    if (is_team_validated(args->args[0]) == false) {
        invalid_team(p, i);
        return (str_to_args_destroy(args));
    }
    if (is_subscription_validated(p->uuids[i], args->args[0]) == true) {
        already_subscribed(p, i);
        return (str_to_args_destroy(args));
    }
    handle_subscribe_success(p, i, args->args[0]);
    str_to_args_destroy(args);
}
