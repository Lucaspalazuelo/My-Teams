/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** search_line.c file.
*/

#include "core.h"

char *search_file_line(char *file_path, char *str, int start_pos, int str_len)
{
    FILE *file = fopen(file_path, "r");
    char *line = NULL;
    size_t length = 0;

    if (file == NULL) {
        return (NULL);
    }
    while (getline(&line, &length, file) != -1) {
        if (strncmp(line + start_pos, str, str_len) == 0) {
            fclose(file);
            return (line);
        }
    }
    fclose(file);
    my_free(line);
    return (NULL);
}
