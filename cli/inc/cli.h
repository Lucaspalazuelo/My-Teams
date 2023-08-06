/*
** EPITECH PROJECT, 2023
** MyTeams - CLI
** File description:
** cli.h file.
*/

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>

#include "../../libs/myteams/logging_client.h"

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define BUFFER_SIZE 1024
#define STR_TO_ARGS_MAX_ARGS 10
#define TEAM 0
#define CHANNEL 1
#define THREAD 2
#define REPLY 3

typedef struct parameters_s {
    int port;
    int count;
    int context;
    char *ip;
    int current_socket;
    int temporary_socket;
    fd_set sockets;
    int command_processed;
    char *uuid;
    char *name;
    char *command;
    char **argv;
} parameters_t;

typedef struct str_to_args_s {
    unsigned int nb_args;
    char **args;
} str_to_args_t;

void error_handling_throw_if_errors(int, char **, parameters_t *);
void error_handling_check_port(char *, parameters_t *);
void error_handling_check_ip(char *, parameters_t *);
void error_handling_unknown_command(parameters_t *);
void my_exit(int, char *, parameters_t *);
void my_free(void *);
void my_write(int, char *);
void print_help(int, char **, parameters_t *);
void free_tab(parameters_t *);

void accept_connections_loop(parameters_t *, int);

void close_socket(parameters_t *, bool);

void connections_loop(parameters_t *);
void connections_loop_read(char *, parameters_t *);

void input_loop(parameters_t *);
void input_loop_write(parameters_t *, char *);

int main(int, char **);

void parameters_init(parameters_t *);
void parameters_destroy(parameters_t *);

void socket_init(parameters_t *);
void socket_create(parameters_t *);

_Noreturn void socket_loop(parameters_t *);
void socket_loop_add_clients(parameters_t *);
void socket_loop_select(parameters_t *);
void socket_loop_accept_connections(parameters_t *);
void socket_loop_handle_connections(parameters_t *);

str_to_args_t *str_to_args(const char *);
str_to_args_t *str_to_args_loop(str_to_args_t *, const char *);
bool str_to_args_compute_logic(str_to_args_t *, char, unsigned int *,
    unsigned int *);
str_to_args_t *str_to_args_malloc(void);
void str_to_args_destroy(str_to_args_t *);

char **my_str_to_word_array(char *, char *);

char *tab_to_str(char **, int);

time_t str_to_time(char *);

void handle_commands(parameters_t *);
void do_commands(parameters_t *, int );

void login(parameters_t *);
void logout(parameters_t *);
void users(parameters_t *);
void print_loop_users(parameters_t *);
void user(parameters_t *);
void send_cmd(parameters_t *);
void messages(parameters_t *);
void print_loop_messages(parameters_t *);
void use(parameters_t *, char *);
void create(parameters_t *);
void list(parameters_t *);
void print_list_loop(parameters_t *);
void context_loop(parameters_t *, str_to_args_t *);
void info(parameters_t *);
void subscribe(parameters_t *);
void unsubscribe(parameters_t *);
