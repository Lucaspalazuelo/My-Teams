/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** generate_uuid.c file.
*/

#include "core.h"

char *generate_uuid(void)
{
    uuid_t uuid;
    char *uuid_str = malloc(sizeof(char) * 37);

    if (uuid_str == NULL) {
        return (NULL);
    }
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_str);
    return (uuid_str);
}
