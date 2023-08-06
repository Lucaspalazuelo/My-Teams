/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** core.h file.
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <uuid/uuid.h>

#include "../../libs/myteams/logging_server.h"

#define STR_TO_ARGS_MAX_ARGS 10
#define MAX_BODY_LENGTH 512
#define BUFFER_SIZE 1024
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_CLIENTS 15
#define UUID_LENGTH 36

#define DATA_USERS_PATH "./server/data/users"
#define DATA_MESSAGES_PATH "./server/data/messages"
#define DATA_TEAMS_PATH "./server/data/teams"
#define DATA_CHANNELS_PATH "./server/data/channels"
#define DATA_THREADS_PATH "./server/data/threads"
#define DATA_REPLIES_PATH "./server/data/replies"
#define DATA_SUBS_PATH "./server/data/subscriptions"
#define ASSETS_HELP_PATH "./server/assets/help"

typedef struct parameters_s {
    unsigned int port;
    int current_socket;
    int temp_socket;
    fd_set sockets;
    int *client_sockets;
    bool is_cmd_executed;
    char **uuids;
    char **team_uuids;
    char **channel_uuids;
    char **thread_uuids;
} parameters_t;

typedef struct str_to_args_s {
    unsigned int nb_args;
    char **args;
} str_to_args_t;

char *register_or_login(str_to_args_t *, char *);

void handle_login(parameters_t *, int, char *);

char *login(char *);

char *create_user(char *);

void handle_login_success(parameters_t *, int, char *, char *);

void handle_create_channel_context(parameters_t *, int, char *);
void handle_create_channel_context_success(parameters_t *, int, char *,
    str_to_args_t *);
void handle_create_channel_context_add(parameters_t *, int, char *,
    str_to_args_t *);

void handle_create(parameters_t *, int, char *);

void handle_create_no_context(parameters_t *, int, char *);
void handle_create_no_context_success(parameters_t *, int, char *,
    str_to_args_t *);
void handle_create_no_context_add(parameters_t *p, int i, char *uuid,
    str_to_args_t *args);

void handle_create_team_context(parameters_t *, int, char *);
void handle_create_team_context_success(parameters_t *, int, char *,
    str_to_args_t *);
void handle_create_team_context_add(parameters_t *, int, char *,
    str_to_args_t *args);

void handle_create_thread_context(parameters_t *, int, char *);
void handle_create_thread_context_success(parameters_t *, int, str_to_args_t *);
void handle_create_thread_context_add(parameters_t *, int , char *,
    str_to_args_t *);

void handle_info_channel_context(parameters_t *, int);

void handle_info(parameters_t *, int, char *);

void handle_info_no_context(parameters_t *, int);

void handle_info_team_context(parameters_t *, int);

void handle_info_thread_context(parameters_t *, int);

void handle_list_channel_context(parameters_t *, int);
void handle_list_channel_context_loop(parameters_t *, int, FILE *);

void handle_list(parameters_t *, int, char *);

void handle_list_no_context(parameters_t *, int);
void handle_list_no_context_loop(parameters_t *, int, FILE *);

void handle_list_team_context(parameters_t *, int);
void handle_list_team_context_loop(parameters_t *, int, FILE *);

void handle_list_thread_context(parameters_t *, int);
void handle_list_thread_context_loop(parameters_t *, int, FILE *);

void handle_print_messages(parameters_t *, int, char *);

void handle_print_messages_loop(parameters_t *, int, FILE *, char *);

void handle_print_user(parameters_t *, int, char *);

void handle_print_user_success(parameters_t *, int, str_to_args_t *, char *);

void handle_print_users(parameters_t *, int, char *);

void handle_print_users_loop(parameters_t *, int, FILE *);

void handle_send_add(str_to_args_t *, parameters_t *, int, char *);

void handle_send(parameters_t *, int, char *);

void handle_send_success(str_to_args_t *, parameters_t *, int);

void handle_subscribe(parameters_t *, int, char *);

void handle_subscribe_success(parameters_t *, int, char *);

void handle_use_channel_context(parameters_t *, int, str_to_args_t *);

void handle_use(parameters_t *, int, char *);

void handle_use_no_context(parameters_t *, int);

void handle_use_team_context(parameters_t *, int, str_to_args_t *);

void handle_use_thread_context(parameters_t *, int, str_to_args_t *);

void handle_help(parameters_t *, int, char *);

void handle_logout(parameters_t *, int, char *);

void close_socket(parameters_t *, int, bool);

void create_socket(parameters_t *);

void init_socket(parameters_t *);

_Noreturn void init_socket_loop(parameters_t *);
void add_socket_connections(parameters_t *);
void select_socket_connections(parameters_t *);
void accept_socket_connections(parameters_t *);
void handle_socket_connections(parameters_t *);

bool add_file_line(char *, char *, bool);

char *search_file_line(char *, char *, int, int);

void already_subscribed(parameters_t *, int);

void invalid_channel(parameters_t *, int);

void invalid_subscription(parameters_t *, int);

void invalid_team(parameters_t *, int);

void invalid_thread(parameters_t *, int);

void invalid_user(parameters_t *, int);

void valid_response(parameters_t *, int);

void destroy_general_handle(char *, str_to_args_t *, FILE *, char *);

void throw_if_errors(int, char **, parameters_t *);
void check_port(char *, parameters_t *);

char *generate_uuid(void);

char *get_timestamp(void);

bool is_channel_validated(char *, char *);

bool is_subscription_validated(char *, char *);

bool is_team_validated(char *);

bool is_thread_validated(char *, char *, char *);

bool is_user_connected(parameters_t *, char *);

bool is_user_validated(char *);

void my_exit(int, char *, parameters_t *);

void my_free(void *);

void my_write(int, char *);

void print_help(int, char **, parameters_t *);

void send_event(parameters_t *, int, char *, char *);

void send_global_event(parameters_t *, int, char *, char *);

str_to_args_t *str_to_args(const char *);
str_to_args_t *str_to_args_loop(str_to_args_t *, const char *);
bool str_to_args_compute_logic(str_to_args_t *, char, unsigned int *,
    unsigned int *);
str_to_args_t *str_to_args_malloc(void);
void str_to_args_destroy(str_to_args_t *);

void read_buffer(parameters_t *, int);
void dispatch_commands(parameters_t *, int, char *);

void load_users(void);

int main(int, char **);

void init_parameters(parameters_t *);
void destroy_parameters(parameters_t *);
