/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** load_users.c file.
*/

#include "core.h"

void load_users(void)
{
    FILE *file = fopen(DATA_USERS_PATH, "r");
    char *line = NULL;
    size_t length = 0;
    str_to_args_t *args = NULL;

    if (file == NULL) {
        return;
    }
    while (getline(&line, &length, file) != -1) {
        args = str_to_args(line);
        if (args == NULL || args->nb_args < 2) {
            str_to_args_destroy(args);
            continue;
        }
        server_event_user_loaded(args->args[0], args->args[1]);
        str_to_args_destroy(args);
    }
    fclose(file);
    my_free(line);
}
