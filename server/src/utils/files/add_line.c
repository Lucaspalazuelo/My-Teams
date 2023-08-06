/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** add_line.c file.
*/

#include "core.h"

bool add_file_line(char *file_path, char *str, bool line_breaking)
{
    FILE *file = fopen(file_path, "a");

    if (file == NULL) {
        return (false);
    }
    fseek(file, 0, SEEK_END);
    if (line_breaking) {
        fprintf(file, "%s\n", str);
    } else {
        fprintf(file, "%s", str);
    }
    fclose(file);
    return (true);
}
