/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** handle_command
*/

#include "cli.h"

void handle_commands(parameters_t *p)
{
    char *cmd[] = {"/login", "/logout", "/users", "/user", "/send", "/messages",
    "/create", "/list", "/info", "/subscribe", "/unsubscribe", NULL};

    if (p->command == NULL)
        return;
    for (int i = 0; cmd[i] != NULL; i++) {
        if (strncmp(p->command, cmd[i], strlen(cmd[i])) == 0) {
            do_commands(p, i);
            return;
        }
    }
}

void do_commands(parameters_t *p, int i)
{
    static void (*commands[])(parameters_t *) = {&login,
    &logout, &users, &user, &send_cmd, &messages, &create, &list, &info,
    &subscribe, &unsubscribe};

    (commands[i])(p);
}
