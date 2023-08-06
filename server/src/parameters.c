/*
** EPITECH PROJECT, 2023
** MyTeams - Server
** File description:
** parameters.c file.
*/

#include "core.h"

void init_parameters(parameters_t *p)
{
    p->client_sockets = malloc(sizeof(int) * MAX_CLIENTS);
    p->uuids = malloc(sizeof(char *) * MAX_CLIENTS);
    p->team_uuids = malloc(sizeof(char *) * MAX_CLIENTS);
    p->channel_uuids = malloc(sizeof(char *) * MAX_CLIENTS);
    p->thread_uuids = malloc(sizeof(char *) * MAX_CLIENTS);
    if (p->client_sockets == NULL || p->uuids == NULL || p->team_uuids == NULL
        || p->channel_uuids == NULL || p->thread_uuids == NULL) {
        my_free(p->client_sockets);
        my_free(p->uuids);
        my_free(p->team_uuids);
        my_free(p->channel_uuids);
        my_free(p->thread_uuids);
        my_exit(84, "Malloc (parameters) failed\n", p);
    }
    for (int i = 0; i < MAX_CLIENTS; i++) {
        close_socket(p, i, false);
    }
}

void destroy_parameters(parameters_t *p)
{
    if (p != NULL) {
        for (int i = 0; i < MAX_CLIENTS && p->uuids != NULL; i++) {
            my_free(p->uuids[i]);
        }
        for (int i = 0; i < MAX_CLIENTS && p->team_uuids != NULL; i++) {
            my_free(p->team_uuids[i]);
        }
        for (int i = 0; i < MAX_CLIENTS && p->channel_uuids != NULL; i++) {
            my_free(p->channel_uuids[i]);
        }
        for (int i = 0; i < MAX_CLIENTS && p->thread_uuids != NULL; i++) {
            my_free(p->thread_uuids[i]);
        }
        my_free(p->uuids);
        my_free(p->client_sockets);
        my_free(p->team_uuids);
        my_free(p->channel_uuids);
        my_free(p->thread_uuids);
    }
    my_free(p);
}
