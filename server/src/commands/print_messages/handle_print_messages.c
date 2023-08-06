/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** handle_print_messages.c file.
*/

#include "core.h"

void handle_print_messages(parameters_t *p, int i, char *buffer)
{
    FILE *file = NULL;
    str_to_args_t *args = NULL;
    char *prefix = "/messages ";

    if (strncmp(buffer, prefix, strlen(prefix)) != 0
        || p->is_cmd_executed == true)
        return;
    file = fopen(DATA_MESSAGES_PATH, "r");
    if (file == NULL)
        return;
    args = str_to_args(buffer);
    if (args == NULL || args->nb_args != 1)
        return (destroy_general_handle(NULL, args, file, NULL));
    if (is_user_validated(args->args[0]) == false) {
        invalid_user(p, i);
        return (destroy_general_handle(NULL, args, file, NULL));
    }
    handle_print_messages_loop(p, i, file, args->args[0]);
    destroy_general_handle(NULL, args, file, NULL);
    valid_response(p, i);
}
