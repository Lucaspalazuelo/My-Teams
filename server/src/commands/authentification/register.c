/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** register.c file.
*/

#include "core.h"

char *create_user(char *username)
{
    char *uuid = generate_uuid();

    if (uuid == NULL) {
        return (NULL);
    }
    add_file_line(DATA_USERS_PATH, "\"", false);
    add_file_line(DATA_USERS_PATH, uuid, false);
    add_file_line(DATA_USERS_PATH, "\" \"", false);
    add_file_line(DATA_USERS_PATH, username, false);
    add_file_line(DATA_USERS_PATH, "\"", true);
    server_event_user_created(uuid, username);
    return (uuid);
}
