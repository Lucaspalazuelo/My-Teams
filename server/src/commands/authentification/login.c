/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** login.c file.
*/

#include "core.h"

char *login(char *line)
{
    str_to_args_t *args = str_to_args(line);
    char *uuid = NULL;

    if (args == NULL || args->nb_args == 0) {
        str_to_args_destroy(args);
        return (NULL);
    }
    uuid = strdup(args->args[0]);
    str_to_args_destroy(args);
    if (uuid == NULL) {
        return (NULL);
    }
    server_event_user_logged_in(uuid);
    return (uuid);
}
