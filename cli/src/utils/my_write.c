/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** my_write.c file.
*/

#include "cli.h"

void my_write(int socket, char *message)
{
    write(socket, message, strlen(message));
}
