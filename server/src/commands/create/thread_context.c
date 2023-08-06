/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** thread_context.c file.
*/

#include "core.h"

void handle_create_thread_context(parameters_t *p, int i, char *buffer)
{
    str_to_args_t *args = str_to_args(buffer);
    char *uuid = NULL;

    if (args == NULL || args->nb_args != 1
        || strlen(args->args[0]) > MAX_BODY_LENGTH) {
        return (str_to_args_destroy(args));
    }
    uuid = generate_uuid();
    if (uuid == NULL) {
        return (str_to_args_destroy(args));
    }
    handle_create_thread_context_add(p, i, uuid, args);
    handle_create_thread_context_success(p, i, args);
    destroy_general_handle(uuid, args, NULL, NULL);
}

void handle_create_thread_context_success(parameters_t *p, int i,
    str_to_args_t *args)
{
    char *timestamp = get_timestamp();
    char *message = malloc(sizeof(char) * (UUID_LENGTH * 3
        + strlen(args->args[0]) + strlen("\"REPLY_CREATED\" ") + 12));

    server_event_reply_created(p->thread_uuids[i], p->uuids[i],
        args->args[0]);
    dprintf(p->client_sockets[i], "OK \"%s\" \"%s\" \"%s\" \"%s\"\n",
        p->team_uuids[i], p->thread_uuids[i], p->uuids[i], args->args[0]);
    if (message != NULL) {
        sprintf(message, "\"REPLY_CREATED\" \"%s\" \"%s\" \"%s\" \"%s\"",
            p->team_uuids[i], p->thread_uuids[i], p->uuids[i], args->args[0]);
        send_global_event(p, i, message, p->team_uuids[i]);
        my_free(message);
    }
    my_free(timestamp);
    p->is_cmd_executed = true;
}

void handle_create_thread_context_add(parameters_t *p, int i, char *uuid,
    str_to_args_t *args)
{
    char *timestamp = get_timestamp();

    add_file_line(DATA_REPLIES_PATH, "\"", false);
    add_file_line(DATA_REPLIES_PATH, uuid, false);
    add_file_line(DATA_REPLIES_PATH, "\" \"", false);
    add_file_line(DATA_REPLIES_PATH, p->thread_uuids[i], false);
    add_file_line(DATA_REPLIES_PATH, "\" \"", false);
    add_file_line(DATA_REPLIES_PATH, p->uuids[i], false);
    add_file_line(DATA_REPLIES_PATH, "\" \"", false);
    add_file_line(DATA_REPLIES_PATH, args->args[0], false);
    add_file_line(DATA_REPLIES_PATH, "\" \"", false);
    add_file_line(DATA_REPLIES_PATH, timestamp, false);
    add_file_line(DATA_REPLIES_PATH, "\"", true);
    my_free(timestamp);
}
