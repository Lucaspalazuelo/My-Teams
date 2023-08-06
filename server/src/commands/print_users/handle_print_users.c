/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_print_users.c file.
*/

#include "core.h"

void handle_print_users(parameters_t *p, int i, char *buffer)
{
    FILE *file = NULL;

    if (strcmp(buffer, "/users") != 0 || p->is_cmd_executed == true) {
        return;
    }
    file = fopen(DATA_USERS_PATH, "r");
    if (file == NULL) {
        return;
    }
    handle_print_users_loop(p, i, file);
    fclose(file);
    valid_response(p, i);
}
