/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** team_context.c file.
*/

#include "core.h"

void handle_create_team_context(parameters_t *p, int i, char *buffer)
{
    str_to_args_t *args = str_to_args(buffer);
    char *uuid = NULL;

    if (args == NULL || args->nb_args != 2
        || strlen(args->args[0]) > MAX_NAME_LENGTH
        || strlen(args->args[1]) > MAX_DESCRIPTION_LENGTH) {
        return (str_to_args_destroy(args));
    }
    uuid = generate_uuid();
    if (uuid == NULL) {
        return (str_to_args_destroy(args));
    }
    handle_create_team_context_add(p, i, uuid, args);
    handle_create_team_context_success(p, i, uuid, args);
    destroy_general_handle(uuid, args, NULL, NULL);
}

void handle_create_team_context_success(parameters_t *p, int i, char *uuid,
    str_to_args_t *args)
{
    char *message = malloc(sizeof(char) * (UUID_LENGTH + 9
        + strlen(args->args[0]) + strlen(args->args[1])
        + strlen("\"CHANNEL_CREATED\" ")));

    server_event_channel_created(p->team_uuids[i], uuid, args->args[0]);
    dprintf(p->client_sockets[i], "OK \"%s\" \"%s\" \"%s\"\n", uuid,
        args->args[0], args->args[1]);
    if (message != NULL) {
        sprintf(message, "\"CHANNEL_CREATED\" \"%s\" \"%s\" \"%s\"", uuid,
            args->args[0], args->args[1]);
        send_global_event(p, i, message, p->team_uuids[i]);
        my_free(message);
    }
    p->is_cmd_executed = true;
}

void handle_create_team_context_add(parameters_t *p, int i, char *uuid,
    str_to_args_t *args)
{
    add_file_line(DATA_CHANNELS_PATH, "\"", false);
    add_file_line(DATA_CHANNELS_PATH, uuid, false);
    add_file_line(DATA_CHANNELS_PATH, "\" \"", false);
    add_file_line(DATA_CHANNELS_PATH, p->team_uuids[i], false);
    add_file_line(DATA_CHANNELS_PATH, "\" \"", false);
    add_file_line(DATA_CHANNELS_PATH, args->args[0], false);
    add_file_line(DATA_CHANNELS_PATH, "\" \"", false);
    add_file_line(DATA_CHANNELS_PATH, args->args[1], false);
    add_file_line(DATA_CHANNELS_PATH, "\"", true);
}
