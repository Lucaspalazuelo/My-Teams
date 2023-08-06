/*
** EPITECH PROJECT, 2023
** my-teams
** File description:
** str_to_time
*/

#include "cli.h"

time_t str_to_time(char *time_str)
{
    struct tm date = {0};
    time_t time;

    sscanf(time_str, "%d-%d-%d %d:%d:%d", &date.tm_year, &date.tm_mon,
    &date.tm_mday, &date.tm_hour, &date.tm_min, &date.tm_sec);
    date.tm_year -= 1900;
    date.tm_mon -= 1;
    time = mktime(&date);
    return time;
}
