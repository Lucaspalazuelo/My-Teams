/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** channel_context.c file.
*/

#include "core.h"

void handle_info_channel_context(parameters_t *p, int i)
{
    char *line = search_file_line(DATA_CHANNELS_PATH, p->channel_uuids[i], 1,
        UUID_LENGTH);

    if (line == NULL) {
        return;
    }
    my_write(p->client_sockets[i], "OK ChannelUUID/TeamUUID/Name/"
        "Description: ");
    my_write(p->client_sockets[i], line);
    my_free(line);
    p->is_cmd_executed = true;
}
