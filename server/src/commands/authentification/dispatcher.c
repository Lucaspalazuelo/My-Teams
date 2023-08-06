/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** dispatcher.c file.
*/

#include "core.h"

char *register_or_login(str_to_args_t *args, char *line)
{
    char *uuid = NULL;

    if (line == NULL) {
        uuid = create_user(args->args[0]);
    } else {
        uuid = login(line);
    }
    return (uuid);
}
