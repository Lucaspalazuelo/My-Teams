/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** channel_context.c file.
*/

#include "core.h"

void handle_create_channel_context(parameters_t *p, int i, char *buffer)
{
    str_to_args_t *args = str_to_args(buffer);
    char *uuid = NULL;

    if (args == NULL || args->nb_args != 2
        || strlen(args->args[0]) > MAX_NAME_LENGTH
        || strlen(args->args[1]) > MAX_BODY_LENGTH) {
        return (str_to_args_destroy(args));
    }
    uuid = generate_uuid();
    if (uuid == NULL) {
        return (str_to_args_destroy(args));
    }
    handle_create_channel_context_add(p, i, uuid, args);
    handle_create_channel_context_success(p, i, uuid, args);
    destroy_general_handle(uuid, args, NULL, NULL);
}

void handle_create_channel_context_success(parameters_t *p, int i, char *uuid,
    str_to_args_t *args)
{
    char *timestamp = get_timestamp();
    char *message = malloc(sizeof(char) * (UUID_LENGTH * 2
        + strlen(timestamp) + strlen(args->args[0])
        + strlen(args->args[1]) + strlen("\"THREAD_CREATED\" ") + 15));

    server_event_thread_created(p->channel_uuids[i], uuid,
        p->uuids[i], args->args[0], args->args[1]);
    dprintf(p->client_sockets[i], "OK \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
        uuid, p->uuids[i], timestamp, args->args[0], args->args[1]);
    if (message != NULL) {
        sprintf(message, "\"THREAD_CREATED\" \"%s\" \"%s\" \"%s\" \"%s\""
            " \"%s\"", uuid, p->uuids[i], timestamp, args->args[0],
            args->args[1]);
        send_global_event(p, i, message, p->team_uuids[i]);
        my_free(message);
    }
    my_free(timestamp);
    p->is_cmd_executed = true;
}

void handle_create_channel_context_add(parameters_t *p, int i, char *uuid,
    str_to_args_t *args)
{
    char *timestamp = get_timestamp();

    add_file_line(DATA_THREADS_PATH, "\"", false);
    add_file_line(DATA_THREADS_PATH, uuid, false);
    add_file_line(DATA_THREADS_PATH, "\" \"", false);
    add_file_line(DATA_THREADS_PATH, p->channel_uuids[i], false);
    add_file_line(DATA_THREADS_PATH, "\" \"", false);
    add_file_line(DATA_THREADS_PATH, p->uuids[i], false);
    add_file_line(DATA_THREADS_PATH, "\" \"", false);
    add_file_line(DATA_THREADS_PATH, args->args[0], false);
    add_file_line(DATA_THREADS_PATH, "\" \"", false);
    add_file_line(DATA_THREADS_PATH, args->args[1], false);
    add_file_line(DATA_THREADS_PATH, "\" \"", false);
    add_file_line(DATA_THREADS_PATH, timestamp, false);
    add_file_line(DATA_THREADS_PATH, "\"", true);
    my_free(timestamp);
}
