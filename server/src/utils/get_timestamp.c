/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** get_timestamp.c file.
*/

#include "core.h"

char *get_timestamp(void)
{
    time_t timestamp;
    struct tm *timestamp_info;
    char *timestamp_str;

    time(&timestamp);
    timestamp_info = localtime(&timestamp);
    timestamp_str = malloc(sizeof(char) * 20);
    if (timestamp_str == NULL) {
        return (NULL);
    }
    strftime(timestamp_str, 20, "%Y-%m-%d %H:%M:%S", timestamp_info);
    return (timestamp_str);
}
